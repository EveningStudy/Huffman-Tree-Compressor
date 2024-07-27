//#include <iostream>
//
//struct Files
//{
//    char fileName[256];
//    int fileSize;
//};
//
//int main(int argc, char* argv[])
//{
//    FILE* fp = fopen(argv[1], "rb");
//    if (fp == NULL)
//    {
//        std::cout << "File open error" << std::endl;
//        std::cin.get();
//        return -1;
//    }
//    int num;
//    fread(&num, 1, 4, fp);
//   std::cout << "num: " << num <<std:: endl;
//    struct Files* fInfo = (struct Files*)malloc(num * sizeof(struct Files));
//
//    fread(fInfo,1, num * sizeof(struct Files), fp);
//    FILE* fpDst;
//    char c; 
//    int r;
//    for (int i = 0; i < num; i++)
//    {
//        fpDst = fopen(fInfo[i].fileName, "wb");
//        for (int j = 0; j < fInfo[i].fileSize; j++)
//        {
//            fread(&c, 1, 1, fp);
//            fwrite(&c, 1, 1, fpDst);
//
//        }
//        fclose(fpDst);
//    }
//    fclose(fp);
//    
//std::cin.get();
//    return 0;
//}
