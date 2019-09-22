# На примере денег

## Часть пятая

Давайте дополним OrderMoney, для того, чтобы наш заказ мог состоять из разного количества позиций.

Начнем c одной.

```c++
make_shared<EqualTest>(
	make_shared<MoneyText>(
		make_shared<OrderMoney>(
			make_shared<RealMoney>(42, "USD")
		)
	),
	"42 USD"
)

OrderMoney::OrderMoney(const shared_ptr<const Money> &a)
	: a(a), b(make_shared<RealMoney>(0, a->currency()))
{
}
```

Теперь переходим к трем или более.

*У данного туториала довольно ограниченный контекст, мы не знаем точно, как будет создаваться OrderMoney.
Возможно обилие конструкторов не решит задачу интеграции Money в продукт.
Оставим это за рамками туториала.*

Для того чтобы передать несколько позиций в один заказ можно воспользоваться объектной композицией. И нам не придется создавать новых классов.

```c++
make_shared<EqualTest>(
	make_shared<MoneyText>(
		make_shared<OrderMoney>(
			make_shared<RealMoney>(1, "USD"),
			make_shared<RealMoney>(2, "USD"),
			make_shared<RealMoney>(4, "USD")
		)
	),
	"7 USD"
)

template <typename T>
OrderMoney(
	const std::shared_ptr<const Money> &a,
	const std::shared_ptr<const Money> &b,
	const std::shared_ptr<const Money> &c,
	const T... &d
) : OrderMoney(std::make_stared<OrderMoney>(a, b), c, d...)
{
}
```

- [ ] $5 + 10CHF = $10 если курс обмена 2:1
- [x] $5 * 2 = $10
- [ ] Money это data class
- [ ] Преобразование Money в текст для отчета
- [x] Общая сумма по всем позициям (простой случай)
- [x] Переименовать TimesMoney в OrderItemMoney со всеми вытекающими.
- [x] Заказ из одной позиции
- [x] Заказ из трех и более позиций
- [ ] Обмен валют

@todo #423 Complete 6 part of money example

[Продолжить](TUTORIAL6.ru.md)
