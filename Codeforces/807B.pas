const fi='';
      fo='';
var p,x,y,r:longint;
function check:boolean;
var i,j:longint;
begin
	i:=(x div 50) mod 475;
	for j:=1 to 25 do
		begin
    		        i:=(i*96+42) mod 475;
                        if i+26=p then exit(true);
                end;
        exit(false);
end;
procedure solve;
var a,b,t:longint;
begin
        a:=0;
        b:=0;
        b:=(x-y) div 50;
        x:=x-b*50;
        while not check do
                begin
                        x:=x+50;
                        inc(a);
                end;
        a:=a-b;
        if a<0 then a:=0;
        t:=a div 2+1;
        if not odd(a) then dec(t);
        write(t);
end;
begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
        readln(p,x,y);
        solve;
        close(input);
        close(output);
end.
