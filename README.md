# C-project2
将棋のコマの動きを表示する。移動できない位置は「◻︎」、移動できる位置は「◾️」、駒自体は「▲」で表示する。
注）23.6.16 現在はmain関数を指定していないため、ターミナルでの表現ができないが、来週には表現できるようにmain関数を指定する。

（解説）
１、盤面は行９、列９のint型配列matrix（以後、Matrix）で管理する。Matrixの各要素は、０〜２の数値が格納され、２は駒の位置、
　１は移動可能位置、０は移動不可位置を表す。
２、コマの移動可能位置は、構造体KOMA（以後、KOMA）で管理する。KOMAは、配列mov（以後、Mov）に指定された駒の移動可能位置が
　方向別に格納され、その格納数（以後、Info)は変数cntにて保持すると定義する。また、それぞれの移動可能位置が駒の位置からどの
  位置にあるかは、駒のいちに変数dy、dxを加算することで求める。
  なお、同一方向に移動可能位置が連続している場合は、繰り返しフラグ（rept）に１が格納され、駒の位置に変数dy、dxの加算を繰り
  返すことで、連続する全ての移動可能位置を求める。
３、１０種類の駒についての移動可能位置を求めるための情報は、KOMAの配列komaInfo（要素数１０）（以後、 KInfo)にあらかじめ
　設定されている。
　要素番号は０〜９まで、「"歩","香","桂","銀","金","飛","角","龍","馬","王"」の順で対応している。
４、関数Display（以後、Display)は、引数で指定され、駒の要素番号に対応した駒の名称とMatrixに格納されているその駒について
　の駒の位置、移動可能位置、移動不可位置を標準出力する。
 　
