**【miniRT レビュー項目】**

前回レビュー項目確認するだけで1時間半かかってしまったので、
スムーズにレビューができるようにレビュー項目をまとめました。
これらの項目をreview用rtファイルで順番に確認していきます。

**【miniRTとは】**

Ray TracingというCG技法の一つ。
物体やカメラの情報が入ったテキストファイルを読み込んで、
物体を３次元空間に配置し、
それをスクリーンという平面に射影することによって
写真のような画像を取得する。

**【miniRT subject 概要】**

設定ファイルを読み込むと、物体とカメラの情報を元に画像を生成する。
`./miniRT test.rt` でその画像を表示
`./miniRT test.rt --save` でその画像をbmpファイルに保存する。

---------------

**【miniRT review項目】**

・norm check
・`make re` して"miniRT"という実行ファイルができることを確認（re-linkしてはいけないよ）
・memory leak check (leaks)

**< error management >**

・ファイルがinvalidな時
（.rtで終わってない時、rtファイルではない時、引数の個数が違う時、ファイルが存在しない時など）
```C
./miniRT aaa
./miniRT aaa.rt
./miniRT
./miniRT a a a a
```
・オプションが違う時
```
./miniRT valid_file.rt --ooo
```
・rtファイルがフォーマットに沿ってない時
 ```
・255,255,
・情報が足りない場合
・ベクトルの大きさが０の時
・途中に変な文字が入っている時
・最後に変な文字が入っている時
```
 (・error.hに22種類のエラーメッセージ書いてあるので確認)

**< configuration file >**

物体に与えられる情報がそれぞれ何なのか確認。

・カメラ、ライト、ウィンドウが課題のフォーマットに沿った設定ファイル (rtファイル)で変更されることを確認

**< technical element of the display >**

以下の６つのテストを実行してください。
1.  ウィンドウだけ表示して、他のブラウザで隠したりしても消えないことを確認
2.  ウィンドウサイズの変更
3.  解像度のチェック
4.  解像度がディスプレイの解像度を上回る時、ディスプレイと同じ解像度にする必要がある (mlx_get_screen_size)（ぴったりだと確認できないので、あえて少しウィンドウより小さく設定してあります）
5.  bmpファイルで保存できているか
6.  esc or 左上の赤いバツを押してウィンドウが閉じるかどうか

**< 5 basic shapes >**

物体に与えられる情報がそれぞれ何なのか確認。

以下を出力せよ
1.   sp (0,0,0)中心
2.   pl z=0
3.   sq (0,0,0) side=10 rgb=(0,0,255)
4.   cy　y軸に平行
5.   tr (0,20,0) (0,0,0) (0,10,20) rgb=(255,255,0)

**< Translation and rotation >**

ここでは物体の移動と回転ができるかをチェック。
・シリンダーを傾けることができるか？（方向ベクトルを(0,-1,1)にする）

**< Multi object >**

オブジェクト同士の交差がうまくいっていることを確認
⓪平面と平面
①円柱と円柱
②球と球
③四角形と四角形
④複数オブジェクト

**< Camera's position and direction >**

あるシーンを作成し、いろんな方向から見る。

**< Brightness 1/2 >**

物体のツヤと影がうまく行っているか？
・sp (0,0,0)中心の球を右から左から照らす
・ずらした点中心の球を右から左から照らす

**< Brightness 2/2 >**

他の物体からの影が表示されるかどうか
・ 垂直に、スポット、球体、平面を配置
・複数オブジェクトで複雑なシーンを出力

**< Multi-spots >**

複数光の時を確認
・違う光からの影が重なった時、重なった部分が暗くなるか？
・ツヤが複数(重なる場合もある)現れるか？

**< bunus >**

必須パートがOKの時のみボーナスを確認する
1つ1ポイント