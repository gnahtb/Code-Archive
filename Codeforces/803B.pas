uses math;
const fi='';
      fo='';
      maxn=200000;
var a,f1,f2,d:array[0..maxn+5] of longint;
    n:longint;
procedure enter;
var i:longint;
begin
        assign(input,fi);
        reset(input);
        readln(n);
        for i:=1 to n do read(a[i]);
        close(input);
end;
procedure init;
var i:longint;
begin
        f1[0]:=-1000000000;
        f2[n+1]:=1000000000;
        for i:=1 to n do
                begin
                        f1[i]:=f1[i-1];
                        if a[i]=0 then f1[i]:=i;
                end;
        for i:=n downto 1 do
                begin
                        f2[i]:=f2[i+1];
                        if a[i]=0 then f2[i]:=i;
                end;
end;
procedure solve;
var i:longint;
begin
        for i:=1 to n do
                d[i]:=min(abs(i-f1[i]),abs(i-f2[i]));
end;
procedure print;
var i:longint;
begin
        assign(output,fo);
        rewrite(output);
        for i:=1 to n do write(d[i],' ');
        close(output);
end;
begin
        enter;
        init;
        solve;
        print;
end.
