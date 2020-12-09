var
	n,m,i,ans,tans:longint;
	k,f:array[0..105] of longint;

function check(x:longint):boolean;
var
	j,tmp:longint;
begin
	for j:=1 to m do
		begin
			tmp:=(k[j]-1) div x+1;
			if tmp<>f[j] then exit(false);
		end;
	check:=true;
end;

begin
	//assign(input,'draft.inp'); reset(input);
	//assign(output,'draft.out'); rewrite(output);
	readln(n,m);
	for i:=1 to m do readln(k[i],f[i]);
	ans:=0;
	for i:=1 to 100 do
		if check(i) then
			begin
					tans:=(n-1) div i+1;
					if ans=0 then ans:=tans
					else
						if ans<>tans then
							begin
								write(-1);
								halt;
							end;
			end;
	write(ans);
	//close(input);
	//close(output);
end.

