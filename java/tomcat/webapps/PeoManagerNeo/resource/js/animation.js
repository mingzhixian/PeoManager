anime({
    targets: ".hello",
    translateY: 400,
    delay: anime.stagger(100, {start: 200}),
    duration: 780
});
var tilte = anime({
    targets: '.tilte',
    translateY: 50,
    duration: 170
});
var pop = anime({
    targets: '.one',
    translateX: 280,
    delay: anime.stagger(100) // 每个元素的延迟增加100毫秒。
});