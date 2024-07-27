//#include <iostream>
//
//struct Files
//{
//    char fileName[256];
//    int fileSize;
//};
//
//int getFileSize(const char* filename)
//{
//    FILE* fp;
//    if (fopen_s(&fp, filename, "r") != 0) {
//        return -1; 
//    }
//
//    fseek(fp, 0, SEEK_END);
//    int size = ftell(fp);
//
//    fseek(fp, 0, SEEK_SET);
//    fclose(fp);
//
//    return size;
//}
//
//int main(int argc, char* argv[])
//{
//    int num = argc - 1;
//    struct Files* fInfo = (struct Files*)malloc(num * sizeof(struct Files));
//    for (int i = 0; i < num; i++) {
//        fInfo[i].fileSize = getFileSize(argv[i + 1]);
//        strcpy_s(fInfo[i].fileName, argv[i + 1]);
//
//        std::cout << i << " " << fInfo[i].fileName << " " << fInfo[i].fileSize << std::endl;
//    }
//    FILE* fp = fopen( "Package.pac", "wb");
//    if (fp == NULL)
//    {
//        return -1;
//    }
//    fwrite(&num, 4, 1, fp);
//    fwrite(fInfo, 1, num * sizeof(struct Files), fp);
//    FILE* fpSrc;
//    int r;
//    char buff[1024];
//    for (int i = 0; i < num; i++)
//    {
//        fpSrc = fopen( fInfo[i].fileName, "rb");
//        if (fpSrc == NULL)
//        {
//			return -1;
//		}
//        while (1)
//        {
//                        r = fread(buff, 1, 1024, fpSrc);
//                        if (r > 0)
//                        {
//                            fwrite(buff, 1, r, fp);
//                        }
//                        else
//                        {
//                            break;
//                        }
//        }
//        fclose(fpSrc);
//    }
//    fclose(fp);
//    free(fInfo);
//    system("pause");
//    
//    return 0;
//} 
