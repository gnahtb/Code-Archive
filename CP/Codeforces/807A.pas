const fi='';
      fo='';
var a,b:array[1..1000] of longint;
    n:longint;
    r:string;
procedure enter;
var i:longint;
begin
        assign(input,fi);
        reset(input);
        readln(n);
        for i:=1 to n do readln(a[i],b[i]);
        close(input);
end;
procedure solve;
var c:boolean;
    i,j:longint;
begin
        r:='rated';
        c:=false;
        for i:=1 to n do if a[i]<>b[i] then c:=true;
        if c then exit;
        r:='maybe';
        for i:=1 to n do
                for j:=1 to i-1 do
                        if b[i]>b[j] then
                                begin
                                        r:='unrated';
                                        exit;
                                end;
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
        solve;
        print;
end.
