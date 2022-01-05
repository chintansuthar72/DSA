#include<iostream>
using namespace std;


// void fun(int *p,int n){
//     //dynamic memory allocation
//     p=(int*)malloc(20);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d",&(*(p+i)));
//         // scanf("%d",&p[i]);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << *(p+i) << " ";
//         // printf("%d ",p[i]);
//     }
//     free(p);  
// }


// void arraya(int arr[][5],int m,int n){

    
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d",&arr[i][j]);
//         }
//     }
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             printf("%d ",arr[i][j]);
//         }printf("\n");
//     }
// }

// void newArr(int** arr,int r,int c){
//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }
//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// } 
int main()
{
    // int arr[5];
    // fun(arr,5);


    // int arr1[4][5];
    // arraya(arr1,4,5);

    
    // int r,c;cin>>r>>c;
    // int** arr=new int* [c];
    // for (int i = 0; i < r; i++)
    // {
    //     arr[i]=new int [c];
    // }
    // newArr(arr,r,c);
    


    // int r,c;cin >> r >> c;
    // int* arr[r];
    // for (int i = 0; i < r; i++)
    // {
    //     arr[i]=(int*)malloc(4*c);
    // }
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < r; i++)
    // {
    //     free(arr[i]);
    // }




//     int c=0;
//     int* p=(int *)malloc(48);
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             scanf("%d",&(*(p+(i*4)+j)));
//             // *(p + i*4 + j)=++c;
//         }
//     }
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             printf("%d ",*(p+ i*4 +j));

//         }printf("\n");
//     }
//     free(p);
    

//     return 0;
// }



// int* matrixmul(int* a1,int* a2){
// 	int* result=(int*)malloc(36);
// 	for (int i = 0; i < 3; i++)
// 	{
// 		for (int j = 0; j < 3; j++)
// 		{
// 			*(result+(3*i)+j)=0;
// 			for (int k = 0; k < 3; k++)
// 			{
// 				*(result+(3*i)+j)+=(*(a1+(3*i)+k))*(*(a2+(3*k)+j));
// 			}
// 		}
// 	}
// 	return result;
// }
// int main(){

// 	int* arr1=(int*)malloc(36);
// 	int* arr2=(int*)malloc(36);

// 	for(int i=0;i<3;i++){
// 		for(int j=0;j<3;j++){
// 			scanf("%d",&(*(arr1+(i*3)+j)));
// 		}
// 	}
//     for(int i=0;i<3;i++){
// 		for(int j=0;j<3;j++){
// 			printf("%d",(*(arr1+(i*3)+j)));
// 		}
// 	}
// 	for(int i=0;i<3;i++){
// 		for(int j=0;j<3;j++){
// 			scanf("%d",&(*(arr2+(i*3)+j)));
// 		}
// 	}

// 	int* p=matrixmul(arr1,arr2);
// 	for(int i=0;i<3;i++){
// 		for(int j=0;j<3;j++){
// 			printf("%d ",(*(p+(i*3)+j)));
// 		}
// 		printf("\n");
// 	}
// 	free(arr1);
// 	free(arr2);
 	return 0;
 }