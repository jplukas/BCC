function decompress(compressedImg, method, k, h)
    img = imread(compressedImg);
    nrows = rows(img);
    ncols = columns(img);
    if (nrows != ncols)
        error("Imagem deve ser quadrada! Dimensoes da imagem: %d x %d", nrows, ncols);
    endif
    nrows = (nrows * (k + 1)) - k;
    decImg = zeros(nrows, nrows, 3, "uint8");
    for i = 0:(ncols-1)
        for j = 0:(ncols-1)
            decImg(1 + i * (k + 1), 1 + j * (k + 1), :) = img(i + 1, j + 1, :);
        endfor
    endfor
    for i = 1:(ncols + k - h + 1)
        for j = 1:(ncols + k - h + 1)
            for t = 1:3
                inter = calc_interp(method, i, j, t);
                for p = 0:(h-1)
                    for q = 0:(h-1)
                        if(mod(p, k + 1) != 0 || mod(q, k + 1) != 0)
                            f = eval_interp(method, inter, i, j, double(p), double(q));
                            decImg(((i - 1) * (k+1) + p + 1), ((j - 1) * (k+1) + q + 1), t) = f;
                        endif
                    endfor
                endfor
            endfor
        endfor
    endfor

    imwrite(decImg,'decompressed.png','Quality',100);

    function interp = calc_bilinear(i, j, t)
        f_00 = img(i, j, t);
        f_10 = img(i + h - k - 1, j, t);
        f_01 = img(i, j + h - k - 1, t);
        f_11 = img(i + h - k - 1, j + h - k - 1, t);
        b = double([f_00;f_10;f_01;f_11]);
        A = [1, 0, 0, 0; 1, h - 1, 0, 0; 1, 0, h - 1, 0; 1, h - 1, h - 1, (h - 1) * (h - 1)];
        interp =  A \ b;
    endfunction

    function val = eval_bilinear(interp, i, j, p, q)
        A = [1, p, q, p * q];
        val = uint8(floor(A * interp));
    endfunction

    function interp = calc_bicub(i, j, t)
        % printf("%d %d\n", i, j);
        f_00 = img(i, j, t);
        f_10 = img(i + h - k - 1, j, t);
        f_01 = img(i, j + h - k - 1, t);
        f_11 = img(i + h - k - 1, j + h - k - 1, t);

        if(j <= h - k - 1)
            dfy_00 = double(f_01 - f_00) / double(h-1);
            dfy_10 = double(f_11 - f_10) / double(h-1);
        else
            dfy_00 = double(f_01 - img(i, j + k - h + 1, t)) / (2.0 * double(h-1));
            dfy_10 = double(f_11 - img(i + h - k - 1, j + k - h + 1, t)) / (2.0 * double(h-1));
        endif
        if(j > ncols - 2 * (h - k - 1))
            dfy_01 = double(f_01 - f_00) / double(h-1);
            dfy_11 = double(f_11 - f_10) / double(h-1);
        else
            dfy_01 = double(img(i, j + 2 * (h - k - 1), t) - f_00) / (2.0 * double(h-1));
            dfy_11 = double(img(i + h - k - 1, j + 2 * (h - k - 1), t) - f_10) / (2.0 * double(h-1));
        endif

        if(i <= h - k - 1)
            dfx_00 = double(f_10 - f_00) / double(h-1);
            dfx_01 = double(f_11 - f_01) / double(h-1);
            dfxy_00 = double(dfy_10 - dfy_00) / double(h-1);
            dfxy_01 = double(dfy_11 - dfy_01) / double(h-1);
        else
            dfx_00 = double(f_10 - img(i + k - h + 1, j, t)) / (2.0 * double(h-1));
            dfx_01 = double(f_11 - img(i + k - h + 1, j + h - k - 1, t)) / (2.0 * double(h-1));
            if(j <= h - k - 1)
                fy_00 = double(img(i + k - h + 1, j + h - k - 1, t) - img(i + k - h + 1, j, t)) / double(h-1);
                fy_01 = double(img(i + k - h + 1, j + 2 * (h - k - 1), t) - img(i + k - h + 1, j, t)) / (2.0 * double(h-1));
            else
                if(j > ncols - 2 * (h - k - 1))
                    fy_01 = double(img(i + k - h + 1, j + h - k - 1, t) - img(i + k - h + 1, j, t)) / double(h-1);
                else
                    fy_01 = double(img(i + k - h + 1, j + 2 * (h - k - 1), t) - img(i + k - h + 1, j, t)) / (2.0 * double(h-1));
                endif
                fy_00 = double(img(i + k - h + 1, j + h - k - 1, t) - img(i + k - h + 1, j + k - h + 1, t)) / (2.0 * double(h-1));
            endif
            dfxy_00 = double(dfy_10 - fy_00) / (2.0 * double(h-1));
            dfxy_01 = double(dfy_11 - fy_01) / (2.0 * double(h-1));
        endif
        if(i > ncols - 2 * (h - k - 1))
            dfx_10 = double(f_10 - f_00) / double(h-1);
            dfx_11 = double(f_11 - f_01) / double(h-1);
            dfxy_10 = double(dfy_10 - dfy_00) / double(h-1);
            dfxy_11 = double(dfy_11 - dfy_01) / double(h-1);
        else
            dfx_10 = double(f_10 - img(i + 2 * (h - k - 1), j, t)) / (2.0 * double(h-1));
            dfx_11 = double(f_11 - img(i + 2 * (h - k - 1), j + h - k - 1, t)) / (2.0 * double(h-1));
            if(j <= h - k - 1)
                dfy_20 = double(img(i + 2 * (h - k - 1), j + h - k - 1, t) - img(i + 2 * (h - k - 1), j, t)) / double(h-1);
                dfy_21 = double(img(i + 2 * (h - k - 1), j + 2 * (h - k - 1), t) - img(i + 2 * (h - k - 1), j, t)) / (2.0 * double(h-1));
            else
                if(j > ncols - 2 * (h - k - 1))
                    dfy_21 = double(img(i + 2 * (h - k - 1), j + h - k - 1, t) - img(i + 2 * (h - k - 1), j, t)) / double(h-1);
                else
                    dfy_21 = double(img(i + 2 * (h - k - 1), j + 2 * (h - k - 1), t) - img(i + 2 * (h - k - 1), j, t)) / (2.0 * double(h-1));
                endif
                dfy_20 = double(img(i + 2 * (h - k - 1), j + h - k - 1, t) - img(i + 2 * (h - k - 1), j + k - h + 1, t)) / (2.0 * double(h-1));
            endif
            dfxy_10 = double(dfy_20 - dfy_00) / (2.0 * double(h-1));
            dfxy_11 = double(dfy_21 - dfy_01) / (2.0 * double(h-1));
        endif
        B = double([
            1, 0, 0, 0;
            1, h-1, (h-1)**2, (h-1)**3;
            0, 1, 0, 0;
            0, 1, 2*(h-1), 3*((h-1)**2);
        ]);
        A = double([
            f_00, f_01, dfy_00, dfy_01;
            f_10, f_11, dfy_10, dfy_11;
            dfx_00, dfx_01, dfxy_00, dfxy_01;
            dfx_10, dfx_11, dfxy_10, dfxy_11;
        ]);

        interp = inv(B) * A * inv(B');
    endfunction

    function val = eval_bicub(interp, i, j, p, q)
        A_1 = [1, p, p ** 2, p ** 3];
        A_2 = [1; q; q ** 2; q ** 3];
        val = uint8(floor(A_1 * interp * A_2));
    endfunction

    function interp = calc_interp(method, i, j ,t)
        if(method==1)
            interp = calc_bilinear(i, j, t);
        else
            interp = calc_bicub(i, j, t);
        endif
    endfunction

    function res_val = eval_interp(method, inter, i, j, p, q)
        if(method==1)
            res_val = eval_bilinear(inter, i, j, p, q);
        else
            res_val = eval_bicub(inter, i, j, p, q);
        endif
    endfunction
endfunction