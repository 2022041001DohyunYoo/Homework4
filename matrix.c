#include <stdio.h>
#include <stdlib.h>

int** make_matrix(int row, int col){//행렬 할당 함수

    int **matrix= (int**) malloc(sizeof(int*) * row); //이중포인터 동적할당

    for(int i = 0; i < row; i ++) {
    matrix[i] = (int*) malloc(sizeof(int) * col); //포인터 동적할당
    }

    //위 과정을 통해 결과적으로 이중 배열의 동적할당 완료

    return matrix; // 할당된 배열의 주소를 반환
}

void free_matrix(int ** matrix, int row){//이중배열 동적할당 해제 함수
    for(int i = 0; i < row; i ++) {
        free(matrix[i]);//포인터 배열의 요소 하나하나 할당 해제
        }
    free(matrix);//포인터 배열 할당 해제
}


void print_matrix(int** matrix, int row, int col ){//행렬 출력 함수

    for(int i = 0; i < row ; i++){
        for(int k = 0; k < col; k++) printf("%d ", matrix[i][k]); //이중반복문을 통해 배열의 모든칸을 출력

        printf("\n");
    }
}


void addition_matrix(int** a,int** b,  int arow, int acol, int brow, int bcol){//행렬합 함수


    if( arow == brow && acol == bcol){//a열의 행과 열의 개수가 b열의 행과 열의 개수가 일치할때만
        
        int** temp = make_matrix(arow, acol); //임시 배열 동적할당
        
        for(int i = 0 ; i < acol ; i ++){
        for(int k = 0 ; k < arow ; k++){//임시배열의 모든 칸을 돌며
            temp[i][k] = a[i][k] + b[i][k];// 임시 배열에 a[i][k] + b[i][k]의 값을 집어넣기
        }
    }
    print_matrix(temp, arow, acol);//임시배열 출력

    free_matrix(temp, arow); //임시배열 동적할당 해제
    }

    else printf(" 행렬 합 연산 불가능 \n\n"); //행렬합이 불가능할 시 출력 메세지
    

}


void subtraction_matrix(int** a,int** b,  int arow, int acol, int brow, int bcol){//행렬차 함수


     if( arow == brow && acol == bcol){//a열의 행과 열의 개수가 b열의 행과 열의 개수가 일치할때만
        int** temp = make_matrix(arow, acol); //임시 배열 동적할당

        for(int i = 0 ; i < arow ; i ++){
        for(int k = 0 ; k < acol ; k++){//임시배열의 모든 칸을 돌며
            temp[i][k] = a[i][k] - b[i][k];// 임시 배열에 a[i][k] - b[i][k]의 값을 집어넣기
        }
     }
    print_matrix(temp, arow, acol);//임시배열 출력

    free_matrix(temp, arow);//임시배열 동적할당 해제
     
    }

    else printf(" 행렬 차 연산 불가능 \n\n"); //행렬차가 불가능할 시 출력 메세지

}


void transpose_matrix(int** a, int arow, int acol){//전치행렬 함수


    int** temp = make_matrix(acol, arow);//임시 배열 동적할당 (행과 열의 개수를 반대로 할당)

    for(int i = 0 ; i < arow ; i ++){
        for(int k = 0 ; k < acol ; k++){//임시배열의 모든 칸을 돌며
            temp[k][i] = a[i][k];//a의 인덱스를 뒤집어서 임시배열에 집어넣기
        } // = a의 행과 열을 뒤집어서 임시배열에 넣어주는 효과
    }

    print_matrix(temp, acol, arow);//임시배열 출력

    free_matrix(temp, acol);
}

void multiply_matrix(int** a,int** b,  int arow, int acol, int brow, int bcol){//행렬곱 함수

    int sum = 0; //행 * 열의 값을 임시로 저장할 변수



    if(acol == brow){//a의 열의 개수와 b의 행의 개수가 일치할때만

        int** temp = make_matrix(arow, bcol);//임시 배열 동적할당 (b의 행의 개수 * a의 열의 개수)

        for(int i = 0 ; i < arow ; i ++){
            for(int k = 0 ; k < bcol ; k++){//임시배열의 모든칸을 돌면서

                for(int n = 0; n < acol; n++) //a행의 열의 = b행의 행의 개수 번 동안
                    sum += a[i][n] * b[n][k]; // 각 성분을 곱해서 sum에 합산
        
                temp[i][k] = sum;// 임시배열의 알맞은 위치에 sum의 값 집어넣기
                sum = 0;//sum 초기화
        }

    }
    print_matrix(temp, arow, bcol); //임시 배열 출력

    free_matrix(temp, arow);

    }

    
    else printf(" 행렬 곱 연산 불가능 \n\n"); //행렬곱이 불가능할 시 출력 메세지

}





int main(){

    int arow, acol, brow;
    int bcol, task, m;

    int n = 1;

    int** A;
    int** B;

    //변수들 선언

    printf("[-----[유도현][2022041001]-----]\n\n");

    printf("a의 행과 열 개수 입력 : ");
    scanf("%d %d", &arow, &acol);//a의 행과 열 개수 입력

    A = make_matrix(arow, acol);//a 동적할당

    printf("b의 행과 열 개수 입력 : ");
    scanf("%d %d", &brow, &bcol);//b의 행과 열 개수 입력

    B = make_matrix(brow, bcol);//b 동적할당


    for(int i = 0 ; i < arow; i ++){//a의 행의 개수 동안 반복

        printf("행렬 a 의 %d번째 행 입력 (%d * %d 행렬) : ", i+1,  arow, acol); // 현재 입력할 행 표시
        for( int k = 0 ; k < acol ; k++){
            scanf("%d", &m);
            A[i][k] = m;
        }//i + 1행의 값 한꺼번에 입력 받기

    }

    printf("\n");

    for(int i = 0 ; i < brow; i ++){// b의 행의 개수 동안 반복

        printf("행렬 b 의 %d번째 행 입력 (%d * %d 행렬) : ", i+1,  brow, bcol);// 현재 입력할 행 표시
        for( int k = 0 ; k < bcol ; k++){
            scanf("%d", &m);
            B[i][k] = m;
        }//i + 1 행의 값 한꺼번에 입력 받기

    }
    


    while(n == 1){
    printf("\n수행할 작업 선택 (1. 행렬 출력 2. 행렬 합 3. 행렬 차 4. 전치행렬 5. 행렬 곱 (유효하지 않은 값 입력시 종료)) : ");
    scanf("%d", &task);//현재 수행할 작업 입력

    switch(task){
    case 1 :

        print_matrix(A, arow, acol);//a 행렬 출력

        printf("\n");

        print_matrix(B, brow, bcol);//b 행렬 출력

        break;

    case 2 :

        addition_matrix(A,B,arow,acol,brow,bcol); //행렬합 함수에 a와 b 넣어서 호출

        break;

    case 3 :

        subtraction_matrix(A,B,arow,acol,brow,bcol);//행렬차 함수에 a와 b 넣어서 호출

        break;

    case 4 :

        transpose_matrix(A,arow,acol);//전치행렬 함수에 a 넣어서 호출

        break;

    case 5 :

        multiply_matrix(A,B,arow,acol,brow,bcol);//행렬곱 함수에 a와 b 넣어서 호출
        
        break;

    default: //종료 명령시

    printf("\n");

    free_matrix(B, brow);//b 할당 해제
    free_matrix(A, arow);//a 할당 해제
    n = 0;//반복 종료
    break;
    }

    
    }





    











}