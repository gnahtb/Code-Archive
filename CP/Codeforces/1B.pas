uses math;
const fi='';
      fo='';
var n,x:longint;
    t1,t2,s:ansistring;
function extract:longint;
var i:longint;
begin
        i:=1;
        t1:='';
        t2:='';
        while s[i] in ['A'..'Z'] do
                begin
                        t1:=t1+s[i];
                        inc(i);
                end;
        while s[i] in ['0'..'9'] DO
                begin
                        t2:=t2+s[i];
                        inc(i);
                end;
        if i=length(s) then exit(1);
        t1:=t2;
        t2:='';
        inc(i);
        while s[i] in ['0'..'9'] do
                begin
                        t2:=t2+s[i];
                        inc(i);
                end;
        exit(2);
end;
procedure solve1;
var r,c,code,i,t:longint;
begin
        c:=0;
        for i:=1 to length(t1) do
                begin
                        t:=(26**(length(t1)-i))*(ord(s[i])-64);
                        c:=c+t;
                end;
        val(t2,r,code);
        writeln('R',r,'C',c);
end;
procedure solve2;
var t,c,code:longint;
begin
        val(t2,c,code);
        t2:='';
        while c>0 do
                begin
                        t:=c mod 26;
                        if t=0 then
                                begin
                                        t:=t+26;
                                        dec(c);
                                end;
                        t2:=chr(t+64)+t2;
                        c:=c div 26;
                end;
        writeln(t2,t1);
end;
begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
        readln(n);
        repeat
                readln(s);
                s:=s+'*';
                x:=extract;
                if x=1 then solve1
                else solve2;
                dec(n);
        until n=0;
        close(input);
        close(output);
end.
