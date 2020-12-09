program ideone;
var i,n,k,min:longint;
    r:int64;
    a:array[1..100000] of longint;
begin	
	readln(n,k);
	min:=maxlongint;
	for i:=1 to n do
		begin
			read(a[i]);
			if a[i]<min then min:=a[i];
		end;
	r:=0;
	for i:=1 to n do
		if (a[i]-min) mod k=0 then
			r:=r+(a[i]-min) div k
		else
			begin
				r:=-1;
				break;
			end;
	write(r);
end.
