const fi='';
      fo='';
var n:ansistring;
    s:longint;
    c:boolean;
    a:array[1..2,1..2] of longint;
procedure enter;
begin
        assign(input,fi);
        reset(input);
        readln(n);
        close(input);
end;
procedure init;
var i,i1,i2:longint;
begin
        s:=0;
        i1:=1;
        i2:=1;
        for i:=length(n) downto 1 do
                begin
                        s:=s+ord(n[i])-48;
                        if (ord(n[i]) mod 3=1) and (i1<=2) then
                                begin
                                        a[1,i1]:=i;
                                        inc(i1);
                                end;
                        if (ord(n[i]) mod 3=2) and (i2<=2) then
                                begin
                                        a[2,i2]:=i;
                                        inc(i2);
                                end;
                end;
end;
procedure print;
begin
        assign(output,fo);
        rewrite(output);
        if c then write(n) else write(-1);
        close(output);
end;
function solve1(x:longint;var xn:ansistring):boolean;
var i:longint;
begin
        for i:=length(xn) downto 1 do
                if (ord(xn[i]) mod 3=x) and (length(xn)>1) then
                        begin
                                delete(xn,i,1);
                                exit(true);
                        end;
        exit(false);
end;
function solve2(x:longint;var xn:ansistring):boolean;
begin
        if length(xn)<=2 then exit;
        if x=1 then
                begin
                        if a[2,1]>0 then delete(xn,a[2,1],1) else exit(false);
                        if a[2,2]>0 then delete(xn,a[2,2],1) else exit(false);
                end;
        if x=2 then
                begin
                        if a[1,1]>0 then delete(xn,a[1,1],1) else exit(false);
                        if a[1,2]>0 then delete(xn,a[1,2],1) else exit(false);
                end;
        exit(true);
end;
procedure solve;
var c1,c2:boolean;
    n1,n2:ansistring;
    t:longint;
begin
        c:=true;
        if s mod 3=0 then exit;
        c:=false;
        n1:=n;
        n2:=n;
        c1:=solve1(s mod 3,n1);
        c2:=solve2(s mod 3,n2);
        while (length(n1)>1) and (n1[1]='0') do delete(n1,1,1);
        while (length(n2)>1) and (n2[1]='0') do delete(n2,1,1);
        t:=length(n);
        if c1 or c2 then c:=true;
        n:='';
        if c1 and (length(n1)<t) and (length(n1)>length(n)) then n:=n1;
        if c2 and (length(n2)<t) and (length(n2)>length(n)) then n:=n2;
end;
begin
        enter;
        fillchar(a,sizeof(a),0);
        init;
        solve;
        print;
end.
