#include <bits/stdc++.h>
using namespace std;
int P_k = 0;//���״洢����������
int mp_m[105][105];//���׼�������0~8��ʾ��Χ8����׵ĸ���
char mp_c[105][105];//������ʾ,*Ϊδ��,^Ϊ��ǵ���,?Ϊ���ɵ���,#Ϊ�Ѵ�
int mp_o[105][105];//���������������
int mp_t[105][105];//����Testģʽ�����������
int n_x[10005];//�洢���Xֵ
int n_y[10005];//�洢���Yֵ
//int n_x_cpy[105];//�洢���������Xֵ(����)
//int n_y_cpy[105];//�洢���������Yֵ(����)
bool sthwr = 0, game_over = 1;
int pt_len = 1;
int pt_x[10005];//����xֵ
int pt_y[10005];//����yֵ
int mp_len = 1;//����ս�ĸ���n*n
bool test = 0;//Debugģʽ
bool re = 0;//�����ж��Ƿ�����
int x, y;//�����x,y
bool Re_re = true;//�����õ�
bool D_ok_b = false;//�ж�����ֵ�Ƿ�Ϸ���bool
char D_ok[20] = { '\0', 'B', 'F', 'G', 'N', 'M', 'P', 'R', 'S', 'T', 'H' };//������������ַ�,��������Ƚ�
double TStart = clock();//��ʼʱ��
double TEnd;//����ʱ��
double BMode[105];//������ʷ��Ϸģʽ���ʱ��
int BTTime[105];//������ʷ��Ϸ���Դ���
void rezero() {
	memset(mp_m, 0, sizeof(mp_m));
	memset(mp_c, 42, sizeof(mp_c));
	memset(mp_o, 0, sizeof(mp_o));
	memset(mp_t, 0, sizeof(mp_t));
	memset(n_x, 0, sizeof(n_x));
	memset(n_y, 0, sizeof(n_y));
	memset(pt_x, 0, sizeof(pt_x));
	memset(pt_y, 0, sizeof(pt_y));
	P_k = 0;
	sthwr = 0;
	game_over = 1;
	pt_len = 1;
	test = 0;
	re = 0;
	x = 1;
	y = 1;
	Re_re = 1;
	return;
}
void re_run()
{
	char M;
	while (Re_re)
	{
		printf("������?\nY��Ϊ��,N��Ϊ��\n");
		while (M = cin.get()) {
			if (M == '\n') {
				continue;
			}
			else {
				break;
			}
		}
		if (M == 'Y')
		{
			re = 1;
			game_over = 0;
			Re_re = 0;
		}
		else if (M == 'N')
		{
			game_over = 0;
			Re_re = 0;
		}
		else
		{
			printf("�ų�,��������ʲô���ų�?\n����֤�Ƿ��в��Ϸ�����ֵ\n\n");
		}
		M = '\0';
	}
	Re_re = 1;
}
void me()
{
	double LTime;
	int LMode;
	FILE* fpt = fopen("HistoryTime.txt", "r");
	FILE* fpm = fopen("HistoryMode.txt", "r");
	fscanf(fpm, "\n%d", &LMode);
	fscanf(fpt, "\n%lf", &LTime);
	fclose(fpt);
	fclose(fpm);
	printf("T����Debugģʽ,S�ر�Debugģʽ,B�˳���Ϸ,R����.\n");
	printf("�����Ϸ�뽫���ױ�ǲ��ύ,����ȷ��ͨ��.\n");
	printf("�������������֮��Ϊ5:1\n");
	printf("�����������Ϊ׼,�������\n");
	printf("�˳���Bug����,ף�������!\n");
	printf("�ϴ���Ϸģʽ: %d * %d\n", LMode, LMode);
	printf("��ʱ%f��\n", LTime);
	printf("*---------------------------------------------------*\n");
	return;
}
void out(int n)//��Ϸģʽ���
{
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
		{
			printf("     ");
		}
		if (i >= 1 && i <= 9)
		{
			printf("%d��: ", i);
		}
		else if (i >= 10)
		{
			printf("%d��:", i);
		}
		for (int k = 1; k <= n; k++)
		{
			if (i >= 1 && k >= 1)
			{
				if (mp_o[i][k] == 1)
				{
					if (mp_m[i][k] == 10)
					{
						printf("0  ");
					}
					else
					{
						if (k >= 1 && k <= 9)
							printf("%d  ", mp_m[i][k]);
						else if (k >= 10)
							printf("%d  ", mp_m[i][k]);
					}
				}
				else  if (mp_o[i][k] == 0)
				{
					printf("%c  ", mp_c[i][k]);
				}
			}
			else if (k <= 9 && k >= 0)
			{
				printf("%d  ", k);
			}
			else if (k >= 10)
			{
				printf("%d ", k);
			}
		}
		printf("\n");
	}
	return;
}
void over_out(int n)//������Ϸ����������
{
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
		{
			printf("     ");
		}
		if (i >= 1 && i <= 9)
		{
			printf("%d��: ", i);
		}
		else if (i >= 10)
		{
			printf("%d��:", i);
		}
		for (int k = 1; k <= n; k++)
		{
			if (i >= 1 && k >= 1)
			{
				if (mp_m[i][k] == 10)
				{
					printf("0  ");
				}
				else
				{
					if (mp_m[i][k] != 9)
					{
						printf("%d  ", mp_m[i][k]);
					}
					else
					{
						printf("$  ");
					}
				}
			}
			else if (k <= 9 && k >= 0)
			{
				printf("%d  ", k);
			}
			else if (k >= 10)
			{
				printf("%d ", k);
			}
		}
		printf("\n");
	}
	return;
}
void out_t(int n)//����ģʽ���
{
	printf("���ʱ,���������&��������ȥ����0.\n");
	for (int i = 1; i <= n; i++)//������������
	{
		for (int k = 1; k <= n; k++)
		{
			if (mp_t[i][k] == 1)
			{
				printf("& ");
			}
			else if (mp_t[i][k] == 0)
			{
				printf("%d ", mp_m[i][k]);
			}
		}
		printf("                 ");
		for (int t = 1; t <= n; t++)
		{
			printf("%c ", mp_c[i][t]);
		}
		printf("\n");
	}
	return;
}
/*
int rest(int n)//4������ĳ�ʼ��(��ת��memsetʵ��)
{
	for (int i = 1; i <= n; i++)//�����������ʼ����char�ʹ���*,int�ʹ���0
	{
		for (int k = 1; k <= n; k++)
		{
			mp_o[i][k] = 0;
			mp_m[i][k] = 0;
			mp_c[i][k] = '*';
			mp_t[i][k] = 0;
		}
	}
	out(n);
	if (test)
	{
		out_t(n);
	}
	return 0;
}*/
bool sc(int x, int y, int n)//��������ֵ��ɨ�裬����Ƿ�������غ�,1ʱ�غ�,0ʱδ�غ�
{
	if (mp_m[x][y] == 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void tg(int x, int y, int num)//�ݹ麯��,������ȥ0�Ĳ���
{
	if (mp_m[x][y] != 0)
	{
		mp_o[x][y] = 1;
	}
	else if (mp_m[x][y] == 0)
	{
		mp_c[x][y] = '#';
		mp_m[x][y] = 10;
		mp_t[x][y] = 1;
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int k = y - 1; k <= y + 1; k++)
			{
				if (!(i != x && k != y) && k != 0 && i != 0 && i <= mp_len && k <= mp_len)
				{
					tg(i, k, num + 1);
				}
			}
		}
	}
	return;
}
bool check_same_pn(int a, int b, int s)//�����Nֵ��Pֵ�Աȣ����ظ�����������
{
	for (int i = 1; i <= s; i++)
	{
		if (pt_x[i] == a && pt_y[i] == b)
		{
			return 1;
		}
	}
	return 0;
}
void gt(int x, int y, int n, char D)//����������ֵ�Ĳ���,��ͼ��
{
	if (D == 'N')//������һ��
	{
		if (sc(x, y, n))//�غϵ����
		{
			//	cout << "Game Over!" << endl << "Boom" << endl;
			TEnd = clock() - TStart;
			printf("Game Over!\nBoom\n");
			mp_c[x][y] = '&';
			//game_over = 0;
			over_out(n);
			re_run();
			return;
		}
		else//δ�غ�
		{
			mp_c[x][y] = '#';
			tg(x, y, 0);
			out(mp_len);
			return;
		}
	}
	else if (D == 'P')//��ǵ���(��ʽ)
	{
		int x_rl, y_rl;//ϣ����Զ�������õ�ȥ����ظ��ı���
		P_k++;
		bool OK_p_xy = 1, Y_ptxy = 0;
		while (OK_p_xy)
		{
			Y_ptxy = 0;
			for (int i = 1; i <= P_k; i++)
			{
				if (x == pt_x[i] && y == pt_y[i])
				{
					Y_ptxy = 1;
				}
			}
			if (Y_ptxy)
			{
				printf("�ظ����,���ڻ����(��ʵ������̫��),���ر�:");
				scanf("%d%d", &x_rl, &y_rl);
				while (! (x_rl >= 1 && x_rl <= mp_len) || ! (y_rl >= 1 && x_rl <= mp_len) || Y_ptxy){
					printf("�ų�,��������ʲô���ų�?\n����֤�Ƿ��в��Ϸ�����ֵ.\n\n");
					scanf("%d%d", &x_rl, &y_rl);
					Y_ptxy = 0;
					for (int i = 1; i <= P_k; i++)
					{
						if (x_rl == pt_x[i] && y_rl == pt_y[i])
						{
							Y_ptxy = 1;
						}
					}
				}
				x = x_rl;
				y = y_rl;
			}
			else
			{
				OK_p_xy = 0;
			}
		}
		mp_c[x][y] = '^';
		pt_x[pt_len] = x;
		pt_y[pt_len] = y;
		pt_len++;
	}
	else if (D == 'G')//��ǵ���(����ʽ,��������̨���ڴ�,�����������Լ�����)
	{
		mp_c[x][y] = '?';
	}
	else if (D == 'M')
	{
		printf("P��orG��?\n");
		D = cin.get();
		while (D == '\n') {
			D = cin.get();
		}
		printf("���������������x,y��λ��.\n");
		//		cin >> x >> y;
		scanf("%d%d", &x, &y);
		if (D == 'P')
		{
			mp_c[x][y] = '*';
			for (int i = 1; i <= pt_len; i++)
			{
				if (x == pt_x[i] && y == pt_y[i])
				{
					printf("fd\n");
					pt_x[i] = 0;
					pt_y[i] = 0;
					break;
				}
			}
		}
		else if (D == 'G')
		{
			mp_m[x][y] = '*';
		}
		else
		{
			printf("�ų�,��������ʲô���ų�?\n����֤�Ƿ��в��Ϸ�����ֵ.\n\n");
		}
	}
	else
	{
		printf("�ų�,��������ʲô���ų�?\n����֤�Ƿ��в��Ϸ�����ֵ.\n\n");
		return;
	}
	out(n);
	if (test)
	{
		out_t(n);
	}
	return;
}
void gen(int s, int n)//�������������(������Χ���ָ���������)
{
	unsigned seed;//�˾�Ϊ������ӳ�ʼ��
	seed = (int)time(0);//�����������ʱ���ֵ
	srand((int)seed);//��int��������Ӽ��ؽ�srand����
	for (int i = 1; i <= s; i++)//�������n��X,Yֵ
	{
		n_x[i] = rand() % n + 1;//�޶�Xֵ��1~n��
		n_y[i] = rand() % n + 1;//�޶�Yֵ��1~n��

/*
		while (n_x[i - 1] == n_x[i] && n_y[i - 1] == n_y[i])//Ӳ��ȥ��(�ϳ�,��˵��Ͷ͵���ǲ���ȡ��)
		{
			n_x[i] = rand() % n + 1;//�޶�Xֵ��1~n��
			n_y[i] = rand() % n + 1;//�޶�Yֵ��1~n��
		}
		if (test == 1)
		{
			cout << n_x[i] << " " << n_y[i] << endl;//����λ�����
		}
*/
	}
	for (int i = 1; i <= s; i++)
	{
		for (int j = 1; j <= s; j++)//���������ϵľ������ظ���Ӳ��ȥ��
		{
			if (i == j)
			{
				break;
			}
			while (n_x[i] == n_x[j] && n_y[i] == n_y[j])
			{
				//				cout << "%%%" << endl;
				n_x[i] = rand() % n + 1;//�޶�Xֵ��1~n��
				n_y[i] = rand() % n + 1;//�޶�Yֵ��1~n��
			}
		}
	}
	for (int i = 1; i <= s; i++)//�����Ե�������Ĳ���
	{
		//		n_x_cpy[i] = n_x[i];//͵������������
		//		n_y_cpy[i] = n_y[i];//͵������������
		mp_m[n_x[i]][n_y[i]] = 9;
		for (int k = n_x[i] - 1; k <= n_x[i] + 1; k++)//����������8���ۼ�1
		{
			for (int m = n_y[i] - 1; m <= n_y[i] + 1; m++)
			{
				if (mp_m[k][m] != 9)
				{
					mp_m[k][m]++;
				}
			}
		}
	}
	return;
}
bool yn_F(int s)//�ύ�Ƿ���ȷ??
{
	int sm_xy = 0;
	/*	sort(pt_x + 1, pt_x + 1 + s);
		sort(pt_y + 1, pt_y + 1 + s);
		sort(n_x_cpy + 1, n_x_cpy + 1 + s);
		sort(n_y_cpy + 1, n_y_cpy + 1 + s);//�������������λ������*/
	for (int i = 1; i < 10005; i++)
	{
		if (mp_m[pt_x[i]][pt_y[i]] == 9)
		{
			cout << n_x[i] << " " << n_y[i] << endl;
			sm_xy++;
		}
	}
	//	cout << "s:" << s << " " << "sm_xy:" << sm_xy << endl;
	if (sm_xy == s)
	{
		printf("You Win!\n");
		game_over = 0;
		TEnd = clock() - TStart;
		TEnd /= 1000;
		if (TEnd < BMode[mp_len]) {
			BMode[mp_len] = TEnd;
		}
		FILE* fpt = fopen("HistoryTime.txt", "w");
		FILE* fpm = fopen("HistoryMode.txt", "w");
		FILE* fpbm = fopen("HistoryBMode.txt", "w");
		for (int i = 1; i <= 100; i++) {
			fprintf(fpbm, " %lf", BMode[i]);
		}
		fprintf(fpm, "\n%d", mp_len);
		fprintf(fpt, "\n%lf", TEnd);
		fclose(fpbm);
		fclose(fpt);
		fclose(fpm);
		return true;
	}
	else
	{
		printf("Game Over!\nWrong Points.\n");
		TEnd = clock() - TStart;
		TEnd /= 1000;
		game_over = 0;
		return false;
	}
}
int move(int n, char D)//������ύ�����Ĵ���
{
	if (D == 'F')
	{
		if (yn_F(n))
		{
			return 1;
		}
		else
		{
			return 1;
		}
	}
	else if (D == 'B')
	{
		game_over = 0;
		re = 0;
		return 3;
	}
	return 0;
}
void bug_fix(int n)//���ڵ�ͼ��ΧһȦ������
{
	for (int i = 0; i <= n + 1; i++)
	{
		for (int k = 0; k <= n + 1; k++)
		{
			if (i == 0 || k == 0 || i == n + 1 || k == n + 1)
			{
				mp_m[i][k] = 0;
			}
		}
	}
	return;
}
int input_int(int input)// ���ݴ��ܵĿ���̨�������뺯��
{
	// ���������ַ�ʱ����ѭ���쳣
	while (!(cin >> input) || cin.peek() != '\n')
	{
		cin.clear();// �ָ�״̬��־
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// �Թ�����
		printf("�ų�,��������ʲô���ų�?\n����֤�Ƿ��в��Ϸ�����ֵ.\n\n");
	}
	return input;
}
void input_int_2()// ���ݴ��ܵĿ���̨�������뺯��(x,y)
{
	// ���������ַ�ʱ����ѭ���쳣
	while (!(cin >> x >> y) || cin.peek() != '\n')
	{
		cin.clear();// �ָ�״̬��־
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// �Թ�����
		printf("�ų�,��������ʲô���ų�?\n����֤�Ƿ��в��Ϸ�����ֵ.\n\n");
	}
	return;
}
int play_main(int n) {//��Ϸ�������в���,����1(2Ϊ��ϰģʽ������)��ʾ������Ϸ,0��ʾ����
	bool backs = 0;
	char D;//��ʱ�Ĳ���
	D_ok_b = 0;
	printf("\n�������Ĳ�����NΪ��������,PΪ�����ױ��,GΪ�²���,FΪ�ύ��ǰ�ĵ��ױ��,M�����������.\n");
	D = cin.get();
	while (D == '\n') {
		D = cin.get();
	}
	for (int i = 1; i <= 20; i++)
	{
		if (D_ok[i] == D)
		{
			D_ok_b = 1;
		}
	}
	if (!D_ok_b)
	{
		printf("�ų�,��������ʲô���ų�?\n����֤�Ƿ��в��Ϸ�����ֵ.\n\n");
		backs = 1;
		return backs;
	}
	if (move(n, D) == 1)
	{
		re_run();
		return backs;
	}
	else if (move(n, D) == 3)
	{
		return backs;
	}
	else if (D == 'T')
	{
		test = 1;
		for (int i = 1; i <= n; i++)
		{
			printf("%d %d\n", n_x[i], n_y[i]);//����λ�����
		}
		backs = 1;
		return backs;
	}
	else if (D == 'S')
	{
		test = 0;
		backs = 1;
		return backs;
	}
	else if (D == 'R')
	{
		game_over = 0;
		re = 1;
		return backs;
	}
	else if (D == 'M')
	{
		gt(1, 1, mp_len, D);
		backs = 1;
		return backs;
	}
	printf("���������������x,y��λ��.\n");
	input_int_2();
	if (x < 1 || x > mp_len || y < 0 || y > mp_len)
	{
		printf("�ų�,��������ʲô���ų�?\n����֤�Ƿ��в��Ϸ�����ֵ.\n\n");
		backs = 1;
		return backs;
	}
	if (D == 'N' && check_same_pn(x, y, mp_len))//�������N��P�غ���������
	{
		printf("��֮ǰ�����P���غ�,����������.\n");
		backs = 1;
		return backs;
	}
	gt(x, y, mp_len, D);//��������Ĳ���
	system("pause");
	return 1;
}
int main()//����������˵
{
again:
	rezero();
	me();
	system("pause");
	int in_times = 1;
	printf("��ֵ����Ϊ5�ı���.\n");
	mp_len = 1;
	while (mp_len % 5 != 0)
	{
		in_times++;//������+1�����ڿ��Ʊ�����Ϣ�����
		mp_len=input_int(mp_len);
		if (mp_len <= 0 ||(in_times != 0 && mp_len % 5 != 0))
		{
			printf("��ֵ����Ϊ5�ı���,������.\n");
			mp_len = 1;
			mp_len=input_int(mp_len);
		}
		if (mp_len > 100)
		{
			printf("����С��100Ŷ,��Ȼ����֤����ù�!\n");
			mp_len = 1;
			continue;
		}
		system("pause");
	}
	int SMT = 0;
//	FILE* fpgt = fopen("HistoryBTime.txt", "r");
	FILE* fpgm = fopen("HistoryBMode.txt", "r");
	FILE* fptt = fopen("HistoryBTTime.txt", "r");
	while (!feof(fpgm)) {
		fscanf(fpgm, " %lf", &BMode[++SMT]);
	}
	SMT = 0;
	while (!feof(fptt)) {
		fscanf(fptt, " %d", &BTTime[++SMT]);
	}
	fclose(fpgm);
	fclose(fptt);
	printf("��ģʽ���Դ���:%d��\n", BTTime[mp_len]);
	if (BMode[mp_len] == 10000000000.000000) {
		printf("��ģʽ��ѳɼ�:%lf��\n", 0);
	}
	else {
		printf("��ģʽ��ѳɼ�:%lf��\n", BMode[mp_len]);
	}
	out(mp_len);
	if (test) {
		out_t(mp_len);
	}
//	rest(mp_len);
	int n;//���׸���
	n = mp_len * mp_len / 5;
	gen(n, mp_len);
	bug_fix(mp_len);
	TStart = clock();
	test = 0;
	game_over = 1;
	while (game_over) {
		if (play_main(n) == 1) {
			TEnd = clock() - TStart;
			TEnd /= 1000;
			printf("%f���ȥ��\n", TEnd);
			continue;
		}
		else {
			break;
		}
	}
	printf("�˴μ�¼:%f��\n", TEnd);
	BTTime[mp_len]++;
	FILE* fptts = fopen("HistoryBTTime.txt", "w");
	for (int i = 1; i <= 100; i++) {
		fprintf(fptts, " %d", BTTime[i]);
	}
	fclose(fptts);
	system("pause");
	if (re)
	{
		re = 0;
		goto again;
	}
	return 0;
}
