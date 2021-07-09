const fi='';
      fo='';
var a:array[1..100,1..100] of longint;
    n,k:longint;
procedure enter;
begin
        assign(input,fi);
        reset(input);
        readln(n,k);
        close(input);
end;
procedure solve(x:longint);
var i,j:longint;
begin
        for i:=1 to n do
                begin
                        if (2*(n-i)+1>k) and (i mod 2<>x) then
                                begin
                                        a[i,i]:=1;
                                        a[i+1,i+1]:=1;
                                        dec(k,2);
                                end
                        else
                                begin
                                        a[i,i]:=1;
                                        dec(k);
                                end;
                        for j:=i+1 to n do
                                if k>0 then
                                        begin
                                                a[i,j]:=1;
                                                a[j,i]:=1;
                                                dec(k,2);
                                        end
                                else exit;
                        if k=0 then exit;
                end;
end;
procedure print;
var i,j:longint;
begin
        assign(output,fo);
        rewrite(output);
        for i:=1 to n do
                begin
                        for j:=1 to n do write(a[i,j],' ');
                        writeln;
                end;
        close(output);
end;
begin
        enter;
        if sqr(n)<k then
                begin
                        write(-1);
                        exit;
                end;
        fillchar(a,sizeof(a),0);
        if k>0 then solve(k mod 2);
        print;
end.
