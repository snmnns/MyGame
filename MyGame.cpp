#include <bits/stdc++.h>
using namespace std;
int P_k = 0;//���״洢����������
int mp_m[105][105];//���׼�������0~8��ʾ��Χ8����׵ĸ���
char mp_c[105][105];//������ʾ,*Ϊδ��,^Ϊ��ǵ���,?Ϊ���ɵ���,#Ϊ�Ѵ�
int mp_o[105][105];//���������������
int mp_t[105][105];//����Testģʽ�����������
int n_x[105];//�洢���Xֵ
int n_y[105];//�洢���Yֵ
//int n_x_cpy[105];//�洢���������Xֵ(����)
//int n_y_cpy[105];//�洢���������Yֵ(����)
bool sthwr = 0,game_over = 1;
int pt_len = 1;
int pt_x[105];//����xֵ
int pt_y[105];//����yֵ
int mp_len = 1;//����ս�ĸ���n*n
bool test = 0;//Debugģʽ
bool re = 0;//�����ж��Ƿ�����
int x, y;//�����x,y
bool Re_re = true;
void re_run()
{
	char M;
    while (Re_re)
	{
		cout << "������?" << endl;
		cout << "Y��Ϊ��,N��Ϊ��" << endl;
		cin >> M;
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
			cout << "�ų�,��������ʲô���ų�?" << endl << "����֤�Ƿ��в��Ϸ�����ֵ" << endl << endl;
		}
		M = '\0';
	}
	Re_re = 1;
}
int me()
{
	cout << "T����Debugģʽ,S�ر�Debugģʽ,B�˳���Ϸ,R����." << endl;
	cout << "�����Ϸ�뽫���ױ�ǲ��ύ,����ȷ��ͨ��." << endl;
	cout << "�������������֮��Ϊ5:1" << endl;
	cout << "�����������Ϊ׼,�������" << endl;
	cout << "�˳���Bug����,ף�������!" << endl;
	cout << "����R������" << endl;
	cout << "*---------------------------------------------------*" << endl;
	return 0;
}
int out(int n)//��Ϸģʽ���
{
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
		{
			cout << "     ";
		}
		if (i >= 1 && i<=9)
		{
			cout << i << "��: ";
		}
		else if (i >= 10)
		{
			cout << i << "��:";
		}
		for (int k = 1; k <= n; k++)
		{
			if (i >= 1 && k >= 1)
			{
				if (mp_o[i][k] == 1)
				{
					if (mp_m[i][k] == 10)
					{
						cout << 0 << "  ";
					}
					else
					{
						if (k >= 1 && k <= 9)
							cout << mp_m[i][k] << "  ";
						else if (k >= 10)
							cout << mp_m[i][k] << "  ";
					}
				}
				else  if (mp_o[i][k] == 0)
				{
					if (k >= 1 && k <= 9)
						cout << mp_c[i][k] << "  ";
					else if (k >= 10)
						cout << mp_c[i][k] << "  ";
				}
			}
			else if (k <=9 && k>=0)
			{
				cout << k << "  ";
			}
			else if (k >= 10)
			{
				cout << k << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
int over_out(int n)//������Ϸ����������
{
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
		{
			cout << "     ";
		}
		if (i >= 1 && i <= 9)
		{
			cout << i << "��: ";
		}
		else if (i >= 10)
		{
			cout << i << "��:";
		}
		for (int k = 1; k <= n; k++)
		{
			if (i >= 1 && k >= 1)
			{
				if (mp_m[i][k] == 10)
				{
					cout << "0" << "  ";
				}
				else
				{
					if (k >= 1 && k <= 9 && mp_m[i][k] != 9)
					{
						cout << mp_m[i][k] << "  ";
					}
					else if (k >= 10 && mp_m[i][k] != 9)
					{
						cout << mp_m[i][k] << "  ";
					}
					else if (mp_m[i][k] == 9)
					{
						cout << "$" << "  ";
					}
				}
			}
			else if (k <= 9 && k >= 0)
			{
				cout << k << "  ";
			}
			else if (k >= 10)
			{
				cout << k << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
int out_t(int n)//����ģʽ���
{
	cout << "���ʱ,���������&��������ȥ����0" << endl;
	for (int i = 1; i <= n; i++)//������������
	{
		for (int k = 1; k <= n; k++)
		{
			if (mp_t[i][k] == 1)
			{
				cout << "&" << " ";
			}
			else if(mp_t[i][k] == 0)
			{
				cout << mp_m[i][k] << " ";
			}
		}
		cout << "                 ";
		for (int t = 1; t <= n; t++)
		{
			cout << mp_c[i][t] << " ";
		}
		cout << endl;
	}
	return 0;
}
int rest(int n)//4������ĳ�ʼ��
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
}
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
int tg(int x, int y, int num)//�ݹ麯��,������ȥ0�Ĳ���
{
	if (mp_m[x][y] != 0)
	{
		mp_o[x][y] = 1;
		return 0;
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
		return 1;
	}
	return 0;
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
int gt(int x, int y,int n,char D)//����������ֵ�Ĳ���,��ͼ��
{
	if (D == 'N')//������һ��
	{
		if (check_same_pn(x, y, n))
		{

		}
		else if (sc(x, y, n))//�غϵ����
		{
			cout << "Game Over!" << endl << "Boom" << endl;
			mp_c[x][y] = '&';
//			game_over = 0;
			over_out(n);
			re_run();
		}
		else//δ�غ�
		{
			mp_c[x][y] = '#';
			tg(x, y, 0);
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
				cout << "�ظ����,���ڻ����(��ʵ������̫��),���ر�:";
				cin >> x_rl >> y_rl;
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
		cout << "P��orG��?" << endl;
		cin >> D;
		cout << "���������������x,y��λ��." << endl;
		cin >> x >> y;
		if (D == 'P')
		{
			mp_c[x][y] = '*';
			for (int i = 1; i <= pt_len;i++)
			{
				if (x == pt_x[i] && y == pt_y[i])
				{
					pt_x[i] = 0;
					pt_y[i] = 0;
					break;
				}
			}
		}
		else if(D == 'G')
		{
			mp_m[x][y] = '*';
		}
		else
		{
			cout << "�ų�,��������ʲô���ų�?" << endl << "����֤�Ƿ��в��Ϸ�����ֵ" << endl << endl;
		}
	}
	else
	{
		cout << "�ų�,��������ʲô���ų�?" << endl << "����֤�Ƿ��в��Ϸ�����ֵ" << endl << endl;
		return 0;
	}
	out(n);
	if (test)
	{
		out_t(n);
	}
	return 0;
}
int gen(int s,int n)//�������������(������Χ���ָ���������)
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
	return 0;
}
int yn_F(int s)//�ύ�Ƿ���ȷ??
{
	int sm_xy = 0;
/*	sort(pt_x + 1, pt_x + 1 + s);
	sort(pt_y + 1, pt_y + 1 + s);
	sort(n_x_cpy + 1, n_x_cpy + 1 + s);
	sort(n_y_cpy + 1, n_y_cpy + 1 + s);//�������������λ������*/
	for (int i = 1; i <= s; i++)
	{
		if (mp_m[n_x[i]][n_y[i]] == 9)
		{
			sm_xy ++;
		}
	}
//	cout << "s:" << s << " " << "sm_xy:" << sm_xy << endl;
	if (sm_xy == s)
	{
		cout << "You Win!" << endl;
		game_over = 0;
		return true;
	}
	else
	{
		cout << "Game Over!" << endl << "Wrong Points" << endl;
		game_over = 0;
		return false;
	}
}
int move(int n,char D)//������ύ�����Ĵ���
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
int bug_fix(int n)//���ڵ�ͼ��ΧһȦ������
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
	return 0;
}
int input_int(int input)// ���ݴ��ܵĿ���̨�������뺯��
{
	// ���������ַ�ʱ����ѭ���쳣
	while (!(cin >> input) || cin.peek() != '\n')
	{
		cin.clear();// �ָ�״̬��־
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// �Թ�����
		cerr << "�ų�,��������ʲô���ų�?" << endl << "����֤�Ƿ��в��Ϸ�����ֵ" << endl << endl;
	}
	return input;
}
int input_int_2()// ���ݴ��ܵĿ���̨�������뺯��(x,y)
{
	// ���������ַ�ʱ����ѭ���쳣
	while (!(cin >> x >> y) || cin.peek() != '\n')
	{
		cin.clear();// �ָ�״̬��־
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// �Թ�����
		cerr << "�ų�,��������ʲô���ų�?" << endl << "����֤�Ƿ��в��Ϸ�����ֵ" << endl << endl;
	}
	return 0;
}
int main()//����������˵
{
again:
	memset(pt_x, 0, 105);
	memset(pt_y, 0, 105);
	bool D_ok_b = false;//�ж�����ֵ�Ƿ�Ϸ���bool
	char D_ok[20] = { '\0', 'B', 'F', 'G', 'N', 'N', 'P', 'R', 'S', 'T' };//������������ַ�,��������Ƚ�
	game_over = 1;
	me();
	system("pause");
	int in_times = 1;
	char D;//��ʱ�Ĳ���,PΪ��ǵ���,NΪ����,GΪ�²��
	cout << "��ֵ����Ϊ5�ı���." << endl;
	mp_len = 1;
	while (mp_len % 5 != 0)
	{
		in_times++;//������+1�����ڿ��Ʊ�����Ϣ�����
		mp_len=input_int(mp_len);
		if (mp_len <= 0 ||(in_times != 0 && mp_len % 5 != 0))
		{
			cout << "��ֵ����Ϊ5�ı���,������." << endl;
			mp_len = 1;
			mp_len=input_int(mp_len);
		}
		if (mp_len > 100)
		{
			cout << "����С��100Ŷ,��Ȼ����֤����ù�!" << endl;
			mp_len = 1;
			continue;
		}
		system("pause");
	}
	rest(mp_len);
	int n = mp_len * mp_len / 5;
	gen(n, mp_len);
	bug_fix(mp_len);
	while (game_over)
	{
		D_ok_b = 0;
		cout << endl << "�������Ĳ�����NΪ��������,PΪ�����ױ��,GΪ�²���,FΪ�ύ��ǰ�ĵ��ױ��,M�����������." << endl;
		cin >> D;
		for (int i = 1; i <= 20; i++)
		{
			if (D_ok[i] == D)
			{
				D_ok_b = 1;
			}
		}
		if (move(n, D) == 1)
		{
			re_run();
			break;
		}
		else if (move(n, D) == 3)
		{
			break;
		}
		else if (D == 'T')
		{
			test = 1;
			for (int i = 1; i <= n; i++)
			{
				cout << n_x[i] << " " << n_y[i] << endl;//����λ�����
			}
			continue;
		}
		else if (D == 'S')
		{
			test = 0;
			continue;
		}
		else if (D == 'R')
		{
			game_over = 0;
			re = 1;
			break;
		}
		else if (D == 'M')
		{
			gt(1, 1, mp_len, D);
			continue;
		}
		else if (! D_ok_b)
		{
			cout << "�ų�,��������ʲô���ų�?" << endl << "����֤�Ƿ��в��Ϸ�����ֵ" << endl << endl;
			continue;
		}
		cout << "���������������x,y��λ��." << endl;
		input_int_2();
		if (x < 1 || x > mp_len || y < 0 || y > mp_len)
		{
			cout << "�ų�,��������ʲô���ų�?" << endl << "����֤�Ƿ��в��Ϸ�����ֵ" << endl << endl;
			continue;
		}
		if (D == 'N' && check_same_pn(x, y, mp_len))//�������N��P�غ���������
		{
			cout << "��֮ǰ�����P���غ�,����������." << endl;
			continue;
		}
		gt(x, y, mp_len, D);//��������Ĳ���
		system("pause");
	}
	system("pause");
	if (re)
	{
		re = 0;
		goto again;
	}
	return 0;
}
