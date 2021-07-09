program ideone;
uses math;
const fi='temp.inp';
      fo='temp.out';
var c,s,s1,n,i,t,t1:longint;
    a:array[1..100000] of longint;
begin
	readln(n);
	for i:=1 to n do read(a[i]);
	s:=0;
	s1:=0;
	for i:=1 to n do
		begin
			if (a[i] mod 2=0) and (a[i]>0) then s:=s+a[i];
			if (a[i] mod 2<>0) and (a[i]>0) then s1:=s1+a[i];
		end;
	s:=s+s1;
	//tim max le am va min le duong
	t:=-1000000004; //max le am
	t1:=1000000004; //min le duong
	for i:=1 to n do
		if a[i] mod 2<>0 then
			begin
				if (a[i]>t) and (a[i]<0) then t:=a[i];
				if (a[i]<t1) and (a[i]>0) then t1:=a[i];
			end;
	if s mod 2=0 then s:=max(s-t1,s+t);
	write(s);
end.
