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

 boolean param精 fatorial 敗呪亜 亨 廃 腰幻 叔楳鞠亀系 馬澗 蝕拝聖 廃陥.


 五乞軒 段引稽 堂携陥壱 蟹身 ばばばばばばばばばばばばばばばばばばばばば 焼 boolean聖 走趨醤馬蟹? stack frame 掩戚亜 畳短 潅嬢蟹摂嬢!
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int boolean = true;
int factMoulder(int a, int b) {
	//factorial with moduler
	//cout << "factorial (" << a << "," << b << ")" << endl;
	if (a == 0 )
		return 1;
	else {
		//cout << "a is.." << a << endl;
		//cout << "fact result is..." << result << endl;
		return (a % b * factMoulder(a - 1, b)) % b;
	}
}

int gcd(int a, int b, bool boolean) {
	//cout << "gcd (" << a << "," << b << ")" << endl;
	if (b == 0) //GCD(a!,b)拭辞 b亜 0戚檎 a 亜 GCD
		return a;
	else {//GCD(b, a!%b)研 毒舘
		if (boolean == true) {
			int c = factMoulder(a, b);
			if (c == 0) //GCD(b, a!%b)拭辞 a!%b亜 0昔 井酔
				return b; 
			return gcd(c, b%c, false);
		}
		return gcd(b, a%b, false);
	}
}

int main(void){
	int a, b;
	cin >> a >> b;
	cout<< gcd(a, b, true) << endl;;
	return 0;
}
