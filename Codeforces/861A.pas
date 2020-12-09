uses math;
var
	p2,p5,n,t,k:int64;
begin
	read(n,k);
	t:=n;
	p2:=0;
	p5:=0;
	while t mod 2=0 do
		begin
			t:=t div 2;
			inc(p2);
		end;
	while t mod 5=0 do
		begin
			t:=t div 5;
			inc(p5);
		end;
	if min(p2,p5)<k then
		begin
			if p2<k then n:=n*(2**(k-p2));
			if p5<k then n:=n*(5**(k-p5));
		end;
	write(n);
end.

