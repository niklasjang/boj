/*
2019-03-13
niklasjang 舌発汐

砧 呪税 置企因鉦呪澗 砧 呪研 蟹袴走 蒸戚 蟹喚 呪 赤澗 亜舌 笛 切尻呪稽 舛税廃陥. 森研 級嬢, 8引 12税 置企因鉦呪澗 GCD(8,12)稽 蟹展鎧壱, 益 葵精 4戚陥. 4澗 8引 12研 蟹喚 呪 赤澗 亜舌 笛 舛呪戚奄 凶庚戚陥. (8引 12税 因鉦呪澗 1, 2, 4亜 赤陥)

切尻呪税 苫塘軒杖精 益 呪左陥 拙暗蟹 旭精 乞窮 丞税 舛呪税 咽戚陥. 森研 級嬢, 5税 苫塘軒杖精 5!稽 蟹展鎧壱 1*2*3*4*5 = 120戚陥. (0!精 1稽 舛廃陥)

砧 呪 n引 k亜 爽嬢然聖 凶, n!引 k税 置企因鉦呪研 姥馬澗 覗稽益轡聖 拙失馬獣神. 森研 級嬢, n = 3, k = 10戚虞檎, GCD(n!,k) = GCD(3!,10) = GCD(1*2*3,10) = GCD(6,10) = 2亜 吉陥.

脊径 : 唖 匝拭 n引 k亜 馬蟹梢 爽嬢遭陥. (0 ‖ n ‖ 1,000,000,000, 1 ‖ k ‖ 1,000,000,000)

窒径 : 脊径税 唖 匝拭 企背辞, n!引 k税 置企因鉦呪研 窒径廃陥.

熱戚 :
10430税 moduler拭辞 壕錘 焼掘 縦聖 紫遂背辞,
n! % k =( (n%k) * (n-1!%k) ) % k
 畳短 笛 呪税 factorial聖 姥廃 陥製拭 GCD研 姥馬澗 依戚 焼艦虞 factorial聖 姥馬澗 引舛拭辞 moduler研 紫遂背辞
 笛 呪税 尻至戚 琶推蒸戚 GCD研 姥廃陥.

 7086_1 : 五乞軒 段引稽 堂携陥壱 蟹身 ばばばばばばばばばばばばばばばばばばばばば

 7086_2 : boolean 走頗壱 薗懐馬惟 幻級醸走幻 recursion聖 床檎 照鞠澗 牛. 食穿備 五乞軒 段引
 7086_3 : recursive源壱 for庚聖 紫遂背辞 熱嬢左切 -> 獣娃 段引
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int factMoulder(int a, int b) {
	//factorial with moduler using for
	int result = 1; //3!%10 熱嬢辞 貸 潤左檎 result亜 訊 1稽 獣拙馬澗走 硝 呪 赤製.
	for (int i = 1; i < a + 1; i++) {
		result = ((i%b) * result ) % b;
	}
	return result;
}

int gcd(int a, int b) {
	//cout << "gcd (" << a << "," << b << ")" << endl;
	if (b == 0) //GCD(a!,b)拭辞 b亜 0戚檎 a 亜 GCD
		return a;
	else {
		return gcd(b, a%b);
	}
}

int main(void) {
	int a, b;
	cin >> a >> b;
	a = factMoulder(a, b);
	cout << gcd(b, a) << endl;;
	return 0;
}
