anime({
    targets: '.one',
    translateX: 280,
    delay: anime.stagger(100, {start: 40}) // 每个元素的延迟增加100毫秒。
});
anime({
    targets: ".hello",
    translateY: 400,
    delay: anime.stagger(100, {start: 80}),
    duration: 780
});