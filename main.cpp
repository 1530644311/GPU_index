#include <iostream>
/**
* ���ݲ���д���ĵ�һ���汾
* ��Ϊֻ�����ޣ������޷�����ͨ����
* v1.0
*/
using namespace std;
    int pageSize = 5;  //Ͱ������
	int overPoint = 0; //���ѵ�
	int h0 = 4;
	int h1 = 8;
    int pages[1000][5] = {
        {
            4,8,12
        },
        {
            5,9
        },
        {
            6
        },
        {
            7,11,15,19,23
        }

    };
    int number_add[1000][1000];//����洢
void hash_new(int old_num[][5],int num){
    for(;overPoint <= num; overPoint++){
        for(int i = 0;i < sizeof(pages[overPoint])/sizeof(pages[0][0]);i++){
            int key = pages[overPoint][i];
            pages[overPoint][i] = 0;
            int number0 = key %h1;
            int mum1 = sizeof(pages[number0])/sizeof(pages[0][0]);
            if(sizeof(pages[number0])/sizeof(pages[0][0])< 5){
                pages[number0][mum1] = key;
            }else{
                int num4 = sizeof(number_add[number0])/sizeof(number_add[number0][0]);
                number_add[number0][num4] = key;
                hash_new(pages,number0);
            }
        }
    }
    int num5 = sizeof(pages[num])/sizeof(pages[0][0]);
    pages[num][num5] = number_add[num][0];
}

int main()
{
	int key;
    cout << "������Ҫ������key" << endl;
    cin>>key;
    int number0 = key %h0;
    int mum1 = sizeof(pages[number0])/sizeof(pages[0][0]);
    if(sizeof(pages[number0])/sizeof(pages[0][0])< 5){
        pages[number0][mum1] = key;
    }else{
        number_add[number0][0] = key;
        hash_new(pages,number0);
    }
    return 0;
}
