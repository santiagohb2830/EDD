/****************************************************************
Fecha 27 de Mayo 2025
Autor: Santiago Hernandez, Juan Esteban Bello, Esteban Navas
Materia: Estructuras de Datos
Tema: Modulo 3 del Proyecto
*****************************************************************/

#ifndef HUFFMAN_H
#define HUFFMAN_H

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

struct HuffmanNode {
    int value;
    int freq;
    HuffmanNode *left, *right;

    HuffmanNode(int v, int f) : value(v), freq(f), left(nullptr), right(nullptr) {}
};

// Comparador para la priority queue

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }   
};

// Funciones a utilizar para el funcionamiento de Huffman

HuffmanNode* buildHuffmanTree(const unordered_map<int, int>& freqMap);

void generateCodes(HuffmanNode* root, string code, unordered_map<int, string>& huffCodes);

void serializeTree(HuffmanNode* node, ostream& out);

HuffmanNode* deserializeTree(istream& in);

void compressMatrix(const vector<vector<int>>& matrix, const string& filename, int meta1, int meta2);

vector<vector<int>> decompressMatrix(const string& filename);


void codificar_img(imagen img, string archivo);

void decodificar_img(string archivo, string nombre);


#include"huffman.hxx"
#endif // HUFFMAN_H
