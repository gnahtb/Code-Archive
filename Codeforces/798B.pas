const fi='';
      fo='';
      max=50;
var s:array[0..max+5] of string;
    f:array[0..max+5,0..max+5] of string;
    r,n:longint;
procedure enter;
var i:longint;
begin
        assign(input,fi);
        reset(input);
        readln(n);
        for i:=1 to n do readln(s[i]);
        close(input);
end;
procedure init;
var i,j:longint;
    t:string;
begin
        for i:=1 to n do
                begin
                        f[i,0]:=s[i];
                        t:=s[i];
                        for j:=1 to length(t)-1 do
                                begin
                                        t:=t+t[1];
                                        delete(t,1,1);
                                        f[i,j]:=t;
                                end;
                end;
end;
procedure solve;
var i,j,k,t,c:longint;
begin
        r:=maxlongint;
        for i:=0 to length(s[1])-1 do
                begin
                        t:=i;
                        c:=1;
                        for j:=2 to n do
                                for k:=0 to length(s[j])-1 do
                                        if f[1,i]=f[j,k] then
                                                begin
                                                        t:=t+k;
                                                        inc(c);
                                                        break;
                                                end;
                        if (c=n) and (t<r) then r:=t;
                end;
        if r=maxlongint then r:=-1;
end;
procedure print;
begin
        assign(output,fo);
        rewrite(output);
        write(r);
        close(output);
end;
begin
        enter;
        init;
        solve;
        print;
end.
