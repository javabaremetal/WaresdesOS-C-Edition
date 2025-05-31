int CriaArquivo(const char *nome, const char *caminho);
int CriaPasta(const char *nome, const char *caminho);
int DeletaItem(const char *tipo, const char *nome, const char *caminho);
int ExisteItem(const char *tipo, const char *nome, const char *caminho);
int GetQuntDirIn(char *dir_rais);
int GetQuntFileIn(char *dir_rais);
char* GetNameFileN(int n, char *dir_rais);
char* GetNameDirN(int n, char *dir_rais);
int GravaByteEmArquivo(char *nome_arquivo, char *dir, unsigned char byte);
int LerByteDoArquivo(char *nome_arquivo, char *dir, int pos);
int TotalBytesNoArquivo(char *nome_arquivo, char *dir);
int LerArquivo(const char *nome, const char *caminho, unsigned char *buffer, int max_size);
#ifndef _USE_DEFINE_FOR_DISK_
#define _USE_DEFINE_FOR_DISK_

#define TYPE_DIR "FOLDER"
#define TYPE_FILE "FILE"

#endif