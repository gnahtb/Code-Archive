program ideone;
var i,a,b,x,y:int64;
begin
	readln(a,b);
	x:=3;
	y:=2;
	i:=1;
	while x*a<=y*b do
		begin
			x:=x*3;
			y:=y*2;
			inc(i);
		end;
	writeln(i);
end.

