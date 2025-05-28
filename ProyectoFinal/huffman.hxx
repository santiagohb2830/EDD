/****************************************************************
Fecha 27 de Mayo 2025
Autor: Santiago Hernandez, Juan Esteban Bello, Esteban Navas
Materia: Estructuras de Datos
Tema: Modulo 3 del Proyecto
*****************************************************************/


#include "huffman.h"
#include "imagen.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <fstream>
#include <bitset>
#include <sstream>
#include <cstdint>

using namespace std;


// Función para construir el árbol de Huffman

HuffmanNode* buildHuffmanTree(const unordered_map<int, int>& freqMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    for (auto& pair : freqMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* merged = new HuffmanNode(-1, left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    return pq.top();
}

// Función para generar el mapa de codificación

void generateCodes(HuffmanNode* root, string code, unordered_map<int, string>& huffCodes) {
    if (!root) return;
    if (root->value != -1) {
        huffCodes[root->value] = code;
    }
    generateCodes(root->left, code + "0", huffCodes);
    generateCodes(root->right, code + "1", huffCodes);
}

// Serializa el árbol de Huffman (para la descompresión)

void serializeTree(HuffmanNode* node, ostream& out) {
    if (!node) {
        out.put('#');  // marcador de nulo
        return;
    }
    if (node->value == -1) {
        out.put('*');
    } else {
        out.put('L');
        out.write(reinterpret_cast<const char*>(&node->value), sizeof(int));
    }
    serializeTree(node->left, out);
    serializeTree(node->right, out);
}

// Deserializa el árbol de Huffman
HuffmanNode* deserializeTree(istream& in) {
    char type;
    in.get(type);
    if (type == '#') return nullptr;

    HuffmanNode* node = nullptr;
    if (type == 'L') {
        int value;
        in.read(reinterpret_cast<char*>(&value), sizeof(int));
        node = new HuffmanNode(value, 0);
    } else {
        node = new HuffmanNode(-1, 0);
    }
    node->left = deserializeTree(in);
    node->right = deserializeTree(in);
    return node;
}

// Codifica la matriz y guarda en archivo binario

void compressMatrix(const vector<vector<int>>& matrix, const string& filename, int meta1, int meta2, int meta3) {
    unordered_map<int, int> freqMap;
    vector<int> flat;

    for (const auto& row : matrix) {
        for (int val : row) {
            freqMap[val]++;
            flat.push_back(val);
        }
    }

    HuffmanNode* root = buildHuffmanTree(freqMap);
    unordered_map<int, string> huffCodes;
    generateCodes(root, "", huffCodes);

    stringstream bitStream;
    for (int val : flat) {
        bitStream << huffCodes[val];
    }

    ofstream out(filename, ios::binary);
    out.write(reinterpret_cast<char*>(&meta1), sizeof(int));
    out.write(reinterpret_cast<char*>(&meta2), sizeof(int));
    out.write(reinterpret_cast<char*>(&meta3), sizeof(int)); // <--- NUEVO

    serializeTree(root, out);

    string bitString = bitStream.str();
    int padding = 8 - (bitString.size() % 8);
    if (padding != 8) {
        bitString.append(padding, '0');
    }

    uint8_t padByte = padding;
    out.write(reinterpret_cast<char*>(&padByte), sizeof(uint8_t));

    for (size_t i = 0; i < bitString.size(); i += 8) {
        bitset<8> byte(bitString.substr(i, 8));
        uint8_t b = static_cast<uint8_t>(byte.to_ulong());
        out.write(reinterpret_cast<char*>(&b), sizeof(uint8_t));
    }

    out.close();
}


// Decodifica el binario a la matriz original

vector<vector<int>> decompressMatrix(const string& filename, int& meta3_out) {
    ifstream in(filename, ios::binary);
    vector<vector<int>> n;
    if (!in.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        return n;; // Retorna una imagen vacía en caso de error
    }

    int meta1, meta2, meta3;
    in.read(reinterpret_cast<char*>(&meta1), sizeof(int));
    in.read(reinterpret_cast<char*>(&meta2), sizeof(int));
    in.read(reinterpret_cast<char*>(&meta3), sizeof(int)); // <--- NUEVO
    meta3_out = meta3;

    HuffmanNode* root = deserializeTree(in);

    uint8_t padByte;
    in.read(reinterpret_cast<char*>(&padByte), sizeof(uint8_t));

    string bitString;
    char byte;
    while (in.read(&byte, 1)) {
        bitset<8> bits(static_cast<unsigned char>(byte));
        bitString += bits.to_string();
    }

    if (padByte > 0 && padByte <= 8) {
        bitString = bitString.substr(0, bitString.size() - padByte);
    }

    vector<int> data;
    HuffmanNode* current = root;
    for (char bit : bitString) {
        if (bit == '0') current = current->left;
        else current = current->right;

        if (current->value != -1) {
            data.push_back(current->value);
            current = root;
        }
    }

    vector<vector<int>> matrix(meta1, vector<int>(meta2));
    int index = 0;
    for (int i = 0; i < meta1; ++i) {
        for (int j = 0; j < meta2; ++j) {
            matrix[i][j] = data[index++];
        }
    }

    return matrix;
}

// Funcion para indicar la imagen y el nombre del archivo resultante a comprimir

void codificar_img(imagen img, string archivo){
	compressMatrix(img.val,archivo,img.val.size(),img.val[0].size(),img.M);
}

// Funcion para reconstruir un archivo comprimido indicandole el nombre de la imagen reconstruida

void decodificar_img(string archivo, string nombre){
	imagen img_rec;
	int m;

	vector<vector<int>> reconstruido = decompressMatrix(archivo, m);
	
	if(reconstruido.empty()){return;}
	
	img_rec.codigo = "P2";
	img_rec.H = reconstruido.size();
	img_rec.W = reconstruido[0].size();
	img_rec.M = m;
	img_rec.val = reconstruido;

	guardarPGM(img_rec,nombre);

	cout << "\nLa imagen ha sido recuperada y almacenada como " << nombre << "\n";
}

/*
// Ejemplo de uso
int main() {
    vector<vector<int>> matriz = {
        {100, 100, 100, 200},
        {200, 200, 200, 100},
        {50,  50,  100, 200}
    };

    int metaExtra = 999; // Meta3
    compressMatrix(matriz, "salida.bin", matriz.size(), matriz[0].size(), metaExtra);

    int meta3_recuperado = 0;
    vector<vector<int>> reconstruida = decompressMatrix("salida.bin", meta3_recuperado);

    cout << "Matriz reconstruida:\n";
    for (const auto& row : reconstruida) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    cout << "Meta3 recuperado: " << meta3_recuperado << "\n";

    return 0;
}

*/
