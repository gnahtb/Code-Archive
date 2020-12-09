program ideone;
var i,m,n,k:longint;
    a:array[1..100000] of int64;
begin
	readln(n,k);
	m:=0;
	i:=2;
	repeat
		while n mod i=0 do
			begin
				inc(m);
				a[m]:=i;
				n:=n div i;
			end;
		inc(i);
	until n=1;
	if m<k then write(-1)
	else
		begin
			if m>k then for i:=1 to m-k do a[i+1]:=a[i]*a[i+1];
			for i:=m-k+1 to m do write(a[i],' ');
		end;
end.
