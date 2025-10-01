// SymbolTable.hpp
#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <stdexcept> 

using namespace std;

class SymbolTable {
private:

    struct SymbolInfo {
        string name;
        string type;
        string value;
        int scope_level;
        bool is_initialized;
        bool is_constant;
        SymbolInfo()
            : name(""), type(""), value(""), scope_level(0), is_initialized(false), is_constant(false) {
        }
        SymbolInfo(const string& n, const string& t, int scope = 0)
            : name(n), type(t), scope_level(scope), is_initialized(false), is_constant(false) {
        }
    };

    unordered_map<string, SymbolInfo> symbols;
    vector<unordered_map<string, SymbolInfo>> scope_stack;
    int current_scope;

public:
    SymbolTable() : current_scope(0) {
        scope_stack.push_back(unordered_map<string, SymbolInfo>());
    }

    // ���������� ������� � ������� ������� ���������
    void addSymbol(const string& name, const string& type, bool is_constant = false) {
        // �������� �� ��������� ����������
        if (symbols.find(name) != symbols.end()) {
            throw runtime_error("Variable '" + name + "' is already declared");
        }

        SymbolInfo info(name, type, current_scope);
        info.is_constant = is_constant;
        symbols[name] = info;
        scope_stack[current_scope][name] = info;
    }

    // ��������� ���� ����������
    string getType(const string& name) {
        if (symbols.find(name) != symbols.end()) {
            return symbols[name].type;
        }
        return "";
    }

    // �������� ������������� ����������
    bool exists(const string& name) {
        return symbols.find(name) != symbols.end();
    }

    // ��������� ���������� � ����������
    SymbolInfo* getSymbolInfo(const string& name) {
        if (symbols.find(name) != symbols.end()) {
            return &symbols[name];
        }
        return nullptr;
    }

    // ��������� ���� ����������� ����������
    vector<string> getAllVariables() {
        vector<string> result;
        for (const auto& pair : symbols) {
            result.push_back(pair.first);
        }
        return result;
    }

    // ����������
    ~SymbolTable() = default;
};