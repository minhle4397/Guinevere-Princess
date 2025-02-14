#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

int Read_FILE(string file_input, int info_knight[], int road_to_Koopa[], string item[]){
    ifstream infile(file_input.c_str(),ios::in); // mở file
    string line;
    int num_element=0;
    int count=0;
    while (getline(infile,line)){
        istringstream iss(line);
        int n,i=0;
        while(iss>>n){
            if(count==0){
                info_knight[i]=n;
            }
            else if(count==1){
                    road_to_Koopa[i]=n;
                    num_element++;
                }
            i++;
            }
    count++;
}
    count=0;
    while(getline(infile,line)){
        istringstream iss(line);
        string token;
        int i=0;
        if(count==2){
        while(getline(iss,token,',')){
            item[i]=token;
            i++;
        }
        }
    count++;
    }
    infile.close();
    return num_element;//xuat ra so lương su kien su kien
}
void event_Processor(int *info_knight, int road_to_Koopa[], string item[],int num_road, int & rescue){ //ham xu ly cac su kien
    int MaxHP=info_knight[0]; //chi so HP ban dau
    int level_present_normal=info_knight[1]; //level luc binh thuong
    bool tiny=false; //trang thai ti hon
    bool frog=false; //trang thái ếch
    int event_tiny=0;
    int event_frog=0;
    bool king=false;//gặp vua Arthur
    bool lancelot=false;//gặp Lancelot
    bool asclepius=false; //được gặp Asclepius 1 lần
    bool merlin=false; //được gặp Merlin 1 lần
    for(int i = 0;i<num_road;i++){
        if(info_knight[0]==999){
            king=true;
        }
        else if(isPrime(info_knight[0]) && !tiny)
            lancelot=true;
        //xu ly su kien so 0 den 5
        if(road_to_Koopa[i]==0){//rong Bowser dau hang va tra cong chua
            rescue=1; //hiep si chien thang khi gap ma su kien la 0
            display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
            break;
        }
        else if(road_to_Koopa[i]==1){//gap Madbear
            if(king || lancelot){
                if(info_knight[1]==10){
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    continue;
                }
                else
                    info_knight[1]++;
            }
            else if(info_knight[1]<levelO(i+1)){
                info_knight[0]=info_knight[0]-damge(1,levelO(i+1));
                if(info_knight[0]<=0 && info_knight[4]>0)
                {
                    info_knight[4]--;
                    info_knight[0]=MaxHP;
                    if(tiny==true)
                        tiny=false;
                }
                else if(info_knight[0]<=0 && info_knight[4]==0){
                    rescue=0;
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    break;
                }
            }
            else if(info_knight[1]==levelO(i+1)){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                continue;
            }
            else{
                if(info_knight[1]==10){
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    continue;
                }
                else{
                    info_knight[1]++;
                    if(frog==false)
                        level_present_normal=info_knight[1];
                }
            }
            if(i!=num_road-1){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
            }

        }
        else if(road_to_Koopa[i]==2){//gap Bandit
             if(i!=num_road-1){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
            }
            if(king || lancelot){
                if(info_knight[1]==10){
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    continue;
                }
                else
                    info_knight[1]++;
            }
            else if(info_knight[1]<levelO(i+1)){
                info_knight[0]=info_knight[0]-damge(1.5,levelO(i+1));
                if(info_knight[0]<=0 && info_knight[4]>0)
                {
                    info_knight[4]--;
                    info_knight[0]=MaxHP;
                    if(tiny==true)
                        tiny=false;
                }
                else if(info_knight[0]<=0 && info_knight[4]==0){
                    rescue=0;
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    break;
                }
            }
            else if(info_knight[1]==levelO(i+1)){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                continue;
            }
            else{
                if(info_knight[1]==10)
                    continue;
                else{
                    info_knight[1]++;
                    if(frog==false)
                        level_present_normal=info_knight[1];
                }
            }

        }
        else if(road_to_Koopa[i]==3){//gap LordLupin
            if(king || lancelot){
                if(info_knight[1]==10){
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    continue;
                }
                else
                    info_knight[1]++;
            }
            else if(info_knight[1]<levelO(i+1)){
                info_knight[0]=info_knight[0]-damge(4.5,levelO(i+1));
                if(info_knight[0]<=0 && info_knight[4]>0)
                {
                    info_knight[4]--;
                    info_knight[0]=MaxHP;
                    if(tiny==true)
                        tiny=false;
                }
                else if(info_knight[0]<=0 && info_knight[4]==0){
                    rescue=0;
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    break;
                }
            }
            else if(info_knight[1]==levelO(i+1)){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                continue;
            }
            else{
                if(info_knight[1]==10){
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    continue;
                }
                else{
                    info_knight[1]++;
                    if(frog==false)
                        level_present_normal=info_knight[1];
                }
            }


        }
        else if(road_to_Koopa[i]==4){//gap Elf

            if(king || lancelot){
                if(info_knight[1]==10){
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    continue;
                }
                else
                    info_knight[1]++;
            }
            else if(info_knight[1]<levelO(i+1)){
                info_knight[0]=info_knight[0]-damge(7.5,levelO(i+1));
                if(info_knight[0]<=0 && info_knight[4]>0)
                {
                    info_knight[4]--;
                    info_knight[0]=MaxHP;
                    if(tiny==true)
                        tiny=false;
                }
                else if(info_knight[0]<=0 && info_knight[4]==0){
                    rescue=0;
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    break;
                }
            }
            else if(info_knight[1]==levelO(i+1)){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                continue;
            }
            else{
                if(info_knight[1]==10){
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    continue;
                }
                else{
                    info_knight[1]++;
                    if(frog==false)
                        level_present_normal=info_knight[1];
                }
            }
            if(i!=num_road-1){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
            }

        }
        else if(road_to_Koopa[i]==5){//gap Troll
            if(king || lancelot){
                if(info_knight[1]==10){
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    continue;
                }
                else
                    info_knight[1]++;
            }
            else if(info_knight[1]<levelO(i+1)){
                info_knight[0]=info_knight[0]-damge(9.5,levelO(i+1));
                if(info_knight[0]<=0 && info_knight[4]>0)
                {
                    info_knight[4]--;
                    info_knight[0]=MaxHP;
                    if(tiny==true)
                        tiny=false;
                }
                else if(info_knight[0]<=0 && info_knight[4]==0){
                    rescue=0;
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    break;
                }
            }
            else if(info_knight[1]==levelO(i+1)){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                continue;
            }
            else{
                if(info_knight[1]==10){
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    continue;
                }
                else{
                    info_knight[1]++;
                    if(frog==false)
                        level_present_normal=info_knight[1];
                }
            }
            if(i!=num_road-1){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
            }
        }
        //xu ly su kien so 6 tro di
        else if(road_to_Koopa[i]==6){//Gap phu thuy Shaman
            if(king || lancelot){
                if(info_knight[1]==10){
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    continue;
                }
                else{
                    info_knight[1]+=2;
                    continue;
                }
            }
            if(tiny==true || frog==true)
                continue;
            if (info_knight[1]>levelO(i+1)){
                if(info_knight[1]==10){
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    continue;
                }
                else
                    info_knight[1]+=2;
                    if(frog==false)
                        level_present_normal=info_knight[1];
            }
            else if(info_knight[1]==levelO(i+1)){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                continue;
            }
            else{
                tiny=true;
                if(info_knight[2]>=1){
                    tiny=false;
                    info_knight[2]--;
                    event_tiny=0;
                }
                else{
                info_knight[0]=info_knight[0]/5;
                if(info_knight[0]<5)
                    info_knight[0]=1;
                }
            }
             if(i!=num_road-1){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
            }
        }
        //Gặp Siren Vajsh
        else if(road_to_Koopa[i]==7){
             if(i!=num_road-1){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
            }
            if(king || lancelot){
                if(info_knight[1]==10){
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    continue;
                }
                else{
                    info_knight[1]++;
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    continue;
                }
            }
            if(tiny==true || frog==true)
                continue;
            if (info_knight[1]>levelO(i+1)){
                if(info_knight[1]==10){
                    display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                    continue;
                }
                else
                    info_knight[1]+=2;
                    if(frog==false)
                        level_present_normal=info_knight[1];
            }
            else if(info_knight[1]==levelO(i+1)){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                continue;
            }
            else{
                frog=true;
                if(info_knight[3]>=1){
                    frog=false;
                    info_knight[3]--;
                    event_frog=0;
                }
                else{
                info_knight[1]=1;
                }
            }

        }
        //Nhặt được nấm tăng lực Mario
        else if(road_to_Koopa[i]==11){
                 if(i!=num_road-1){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
            }
                int n1=((info_knight[1]+info_knight[4])%5+1)*3;
                int s1=sumOfNLargestOddDigits(n1);
                info_knight[0]=info_knight[0]+(s1%100);
                info_knight[0]=findNearestPrime(info_knight[0]); //Số máu là số nguyên tố gần nhất
                if(info_knight[0]>MaxHP)
                    info_knight[0]=MaxHP;

        }
        //Nhặt được nấm Fibonacci
        else if(road_to_Koopa[i]==12){
             if(i!=num_road-1){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
            }
            if(info_knight[0]>1){
                info_knight[0]=fibonacci_near(info_knight[0]);
            }

        }
        //Nhặt được nấm ma MushGhost
        else if(count_digits(road_to_Koopa[i])>=3){
                int num_mush;//số lượng nấm mush ghost
                int* arr_num_ghost=extract_digits(road_to_Koopa[i],num_mush); //mảng nấm ma
                int n2; //dòng đầu file MushGhost
                int* arr_n2 = read_data_from_file_MushGhost(item[0],n2);//mảng trong file nấm ma
                for(int j=2;j<num_mush;j++){
                        if(arr_num_ghost[j]==1){//nấm ma loại 1
                            int maxi,mini;
                            find_pos_final_min_max(arr_n2,n2,mini,maxi);
                            info_knight[0]=info_knight[0]-(maxi+mini);
                            if(info_knight[0]>MaxHP)
                                info_knight[0]=MaxHP;
                            else if(info_knight[0]<=0 && info_knight[4]>0){
                                info_knight[4]--;
                                info_knight[0]=MaxHP;
                                if(tiny==true)
                                    tiny=false;
                            }
                            else if(info_knight[0]<=0 && info_knight[4]==0){
                                rescue=0;
                                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                                break;
                            }
                        }
                        else if(arr_num_ghost[j]==2){//nấm ma loại 2
                            int mtx,mti;// lần lượt là giá trị và vị trí của đỉnh núi
                            checkMountainShape(arr_n2,n2,mtx,mti);
                            info_knight[0]=info_knight[0]-(mtx+mti);
                            if(info_knight[0]>MaxHP)
                                info_knight[0]=MaxHP;
                            else if(info_knight[0]<=0 && info_knight[4]>0){
                                info_knight[4]--;
                                info_knight[0]=MaxHP;
                                if(tiny==true)
                                    tiny=false;
                            }
                            else if(info_knight[0]<=0 && info_knight[4]==0){
                                rescue=0;
                                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                                break;
                            }
                        }
                        else if(arr_num_ghost[j]==3){//nấm ma loại 3
                            int maxi2,mini2;
                            int arr_n2_copy[n2];
                            for(int k=0;k<n2;k++){
                                arr_n2_copy[i]=arr_n2[i];
                            }
                            for(int k=0;k<n2;k++){
                                if(arr_n2_copy[k]<0)
                                    arr_n2_copy[k]=-arr_n2_copy[k];
                                else
                                    arr_n2_copy[k]=(17*arr_n2_copy[k]+9)%257;
                            }
                            find_pos_first_min_max(arr_n2_copy,n2,maxi2,mini2);
                            info_knight[0]=info_knight[0]-(maxi2+mini2);
                            if(info_knight[0]>MaxHP)
                                info_knight[0]=MaxHP;
                            else if(info_knight[0]<=0 && info_knight[4]>0){
                                info_knight[4]--;
                                info_knight[0]=MaxHP;
                                if(tiny==true)
                                    tiny=false;
                            }
                            else if(info_knight[0]<=0 && info_knight[4]==0){
                                rescue=0;
                                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                                break;
                            }

                        }
                        else if(arr_num_ghost[j]==4){//nấm ma loại 4
                            int max2_3x,max2_3i;
                            int arr_n2_copy1[n2];
                            for(int k=0;k<n2;k++){
                                arr_n2_copy1[i]=arr_n2[i];
                            }
                            for(int k=0;k<n2;k++){
                                if(arr_n2_copy1[k]<0)
                                    arr_n2_copy1[k]=-arr_n2_copy1[k];
                                else
                                    arr_n2_copy1[k]=(17*arr_n2_copy1[k]+9)%257;
                            }
                            find_max2_3(arr_n2_copy1,n2,max2_3x,max2_3i);
                            info_knight[0]=info_knight[0]-(max2_3x+max2_3i);
                            if(info_knight[0]>MaxHP)
                                info_knight[0]=MaxHP;
                            else if(info_knight[0]<=0 && info_knight[4]>0){
                                info_knight[4]--;
                                info_knight[0]=MaxHP;
                                if(tiny==true)
                                    tiny=false;
                            }
                            else if(info_knight[0]<=0 && info_knight[4]==0){
                                rescue=0;
                                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                                break;
                            }
                        }
                }
                delete[] arr_n2;// khi sử dụng xong
                delete[] arr_num_ghost;

        }
        else if(road_to_Koopa[i]==15 || road_to_Koopa[i]==16 || road_to_Koopa[i]==17){
            if(i!=num_road-1){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
            }
            if(road_to_Koopa[i]==15 && info_knight[2]<99)
                info_knight[2]++;
            else if(road_to_Koopa[i]==16 && info_knight[3]<99)
                info_knight[3]++;
            else if(road_to_Koopa[i]==17 && info_knight[4]<99)
                info_knight[4]++;

        }
        else if(road_to_Koopa[i]==19) {//Gặp Asclepius
             if(i!=num_road-1){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
            }
            if(asclepius==false){
                asclepius=true;
            }
            else
                continue;
            int r1,c1;
            int s_temp[3]={0,0,0}; //mảng để lưu số lượng số 16 17 18
            int** matrix_item=readMatrixFromFile(item[1],r1,c1);
            int re=0;
            int mai=0;
            int phoe=0;
            for(int a=0;a<r1;a++){
                 re=0;
                 mai=0;
                 phoe=0; //biến đếm số lượng mỗi dòng
                for(int b=0;b<c1;b++){
                        if(matrix_item[a][b]==16 && re!=1){
                            s_temp[0]++;
                            re++;
                        }
                        else if(matrix_item[a][b]==17 && mai!=1){
                            s_temp[1]++;
                            mai++;
                        }
                        else if(matrix_item[a][b]==18 && phoe!=1){
                            s_temp[2]++;
                            phoe++;
                        }
                }
            }
            for (int a = 0; a < r1; a++)
                delete[] matrix_item[a];

            delete[] matrix_item;
            info_knight[2]+=s_temp[0];
            info_knight[3]+=s_temp[1];
            info_knight[4]+=s_temp[2];
            if(tiny==true){
                info_knight[2]--;
                tiny=false;
            }
            else if(frog==true){
                info_knight[3]--;
                frog=false;
            }

        }

        //Gặp Bowser
        else if(road_to_Koopa[i]==99){
             if(i!=num_road-1){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
            }
            if(king==true)
                info_knight[1]=10;
            else if(lancelot==true && info_knight[1]>=8){
                info_knight[1]=10;
            }
            else if(info_knight[1]==10){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                continue;
            }
            else{
                info_knight[0]=0;
                rescue=0;
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
                break;
            }

        }
        //Gặp phù thủy Merlin
        else if(road_to_Koopa[i]==18){
             if(i!=num_road-1){
                display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
            }
            if(merlin==false)
                merlin=true;
            else
                continue;
            int mer_2=0;
            int mer_3=0;
            readFile_merlin_pack(mer_3,mer_2,item[2]);
            if(info_knight[0]<MaxHP){
                info_knight[0]= info_knight[0]+ mer_2*2 + mer_3*3;
                if(info_knight[0]>MaxHP)
                    info_knight[0]=MaxHP;
            }

        }
        //kiem tra so lan hoa ti hon neu co thuoc giai thi giai doc
        if(tiny==true){
            if(event_tiny<3)
                event_tiny++;
            else {
                tiny=false;
                info_knight[0]=info_knight[0]*5;
                if(info_knight[0]>MaxHP)
                    info_knight[0]=MaxHP;
            }
            if(info_knight[2]>=1){
                    tiny=false;
                    info_knight[2]--;
                    event_tiny=0;
                }
        }
        //kiem tra so lan hoa thanh con ech neu co thuoc giai thi giai doc
        if(frog==true){
            if(event_frog<3)
                event_frog++;
            else {
                frog=false;
                info_knight[1]=level_present_normal;
            }
            if(info_knight[3]>=1){
                    frog=false;
                    info_knight[3]--;
                    event_frog=0;
                }
        }

        if(info_knight[0]>0 && i==num_road-1){
            rescue=1;
            display(info_knight[0],info_knight[1],info_knight[2],info_knight[3],info_knight[4],rescue);
        }
    }


}
void readFile_merlin_pack(int& a, int& b, string filename) {// đọc file merlin pack
    ifstream file(filename);
    int n;
    file >> n;

    string line;
    getline(file, line);

    for (int i = 0; i < n; i++) {
        getline(file, line);
        bool found = false;
        for (int j = 0; j < line.length() - 5; j++) {
            if ((line[j] == 'M' || line[j] == 'm') &&
                (line[j+1] == 'E' || line[j+1] == 'e') &&
                (line[j+2] == 'R' || line[j+2] == 'r') &&
                (line[j+3] == 'L' || line[j+3] == 'l') &&
                (line[j+4] == 'I' || line[j+4] == 'i') &&
                (line[j+5] == 'N' || line[j+5] == 'n')) {
                found = true;
                b++;
                break;
            }
        }
        if (found || line.find("Merlin") != std::string::npos ||
            line.find("merlin") != std::string::npos) {
            a++;
        }
    }
    file.close();
}
int** readMatrixFromFile(string filename, int& n, int& m) {//đọc file Asclepius và trả về ma trận
    ifstream file(filename);

    file >> n >> m;

    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++) {
            file >> matrix[i][j];
        }
    }

    file.close();

    return matrix;
}

void find_max2_3(int arr[], int size, int& max2_3x, int& max2_3i) {//tìm giá trị và vị trí của số lớn thứ 2 trong 3 số đầu tiên của dãy
    max2_3x = max2_3i = -1;
    int max1 = arr[0];
    for (int i = 1; i < min(3, size); i++) {
        if (arr[i] > max1) {
            max2_3x = max1;
            max2_3i = i-1;
            max1 = arr[i];
        } else if (arr[i] != max1 && (max2_3x == -1 || arr[i] > max2_3x)) {
            max2_3x = arr[i];
            max2_3i = i;
        }
    }
    if (max2_3x == -1) {
        max2_3x = -5;
        max2_3i = -7;
    }
}

int find_first_occurrence(int arr[], int n, int x) {//tìm 1 số xuất hiện đầu tiên trong mảng
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1; // Không tìm thấy
}
void find_pos_first_min_max(int arr[], int n, int& maxi2, int& mini2) {//tìm vị trí số lớn nhất và nhỏ nhất xuất hiện đầu tiên
    int max_val = arr[0], min_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    maxi2 = find_first_occurrence(arr, n, max_val);
    mini2 = find_first_occurrence(arr, n, min_val);
}
void checkMountainShape(int arr[], int n, int &mtx, int &mti) {//kiểm tra dãy có hình dạng đỉnh núi không
    int i = 0;
    while (i < n - 1 && arr[i] < arr[i+1]) {
        i++;
    }
    if (i == 0 || i == n - 1) {
        mtx = arr[i];
        mti = i;
        while (i < n - 1 && arr[i] > arr[i+1]) {
            i++;
        }
        if (i == n - 1) {
            return;
        }
    }
    mtx = -2;
    mti = -3;
    return;
}

void find_pos_final_min_max(int arr[], int n, int& a, int& b) {//tìm vị trí cuối cùng của số lớn nhất và nhỏ nhất
    int min_val = arr[0], max_val = arr[0];
    a = b = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
            a = i;
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
            b = i;
        }
    }
}
int* extract_digits(int n, int& size) {
    int* arr = new int[100];
    size = 0;

    while (n > 0) {
        arr[size++] = n % 10;
        n /= 10;
    }

    return arr;
}
int count_digits(int n) {//đếm số chữ số
    int count = 0;

    while (n > 0) {
        count++;
        n /= 10;
    }

    return count;
}
int* read_data_from_file_MushGhost(string filename, int& n) {// hàm lấy dữ liệu từ file MushGhost
    ifstream input_file(filename);

    input_file >> n;

    int* data = new int[n];

    for (int i = 0; i < n; i++) {
        input_file >> data[i];
    }

    input_file.close();
    return data;
}

int fibonacci_near(int n) {

    // Khởi tạo hai số Fibonacci đầu tiên
    int fib1 = 1, fib2 = 1;

    // Tính các số Fibonacci cho đến khi số Fibonacci lớn hơn hoặc bằng n
    while (fib2 <= n) {
        int temp = fib2;
        fib2 = fib1 + fib2;
        fib1 = temp;
    }

    // Trả về số Fibonacci gần nhất và thấp hơn n
    return fib1;
}
int absoluteValue(int num) {
    if(num < 0)
        return -num;
    else
        return num;
}
bool isPrime(int n) {//kiem tra so nguyen to
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int findNearestPrime(int n) {//lay so nguyen to gan nhat
    int smaller = n - 1;
    int larger = n + 1;
    while (!isPrime(smaller)) {
        smaller--;
    }
    while (!isPrime(larger)) {
        larger++;
    }
    if (absoluteValue(n-smaller) <= absoluteValue(n-larger)) {
        return smaller;
    }
    else {
        return larger;
    }
}
int sumOfNLargestOddDigits(int n) {
    // Tạo mảng chứa tất cả các số nguyên dương lẻ có 2 chữ số
    int arr[45], k = 0;
    for (int i = 11; i <= 99; i += 2) {
        arr[k++] = i;
    }

    // Sắp xếp mảng theo thứ tự giảm dần
    for (int i = 0; i < k-1; i++) {
        for (int j = i+1; j < k; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Lấy tổng n số đầu tiên trong mảng
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

int levelO(int event_no){ //level cua doi thu
    int b = event_no%10;
    return event_no>6?(b>5?b:5):b;

}
int damge(double baseDam, int levelBoss){ //damge cua doi thu
    return baseDam*levelBoss*10;
}
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {

    rescue=-1;
    int info_knight[5];
    int road_to_Koopa[20];
    string item[3];
    int num_road =  Read_FILE(file_input,info_knight,road_to_Koopa,item);
    event_Processor(info_knight,road_to_Koopa,item,num_road,rescue);
    /*HP=info_knight[0];
    level=info_knight[1];
    remedy=info_knight[2];
    maidenkiss=info_knight[3];
    phoenixdown=info_knight[4];
    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);*/



}
