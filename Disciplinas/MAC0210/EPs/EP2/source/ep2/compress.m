function compress(originalImg, k)
    img = imread(originalImg);
    if(columns(img) != rows(img))
        error("Imagem deve ser quadrada!");
    endif
    if(mod(columns(img), k + 1) != 1)
        error("Valor de k inválido!");
    endif
    img = img(1:k+1:end, :, :);
    img = img(:, 1:k+1:end, :);
    imwrite(img,'compressed.png','Quality',100);
endfunction