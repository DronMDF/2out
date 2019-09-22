# На примере денег

## Часть четвертая

Теперь мы можем приступить к реализации OrderMoney, общуй суммы заказа.

```c++
make_shared<EqualTest>(
	make_shared<MoneyText>(
		make_shared<OrderMoney>(
			make_shared<RealMoney>(5, "USD"),
			make_shared<RealMoney>(7, "USD")
		)
	),
	"12 USD"
)
```

Стоит обратить внимание, что мне не нужен класс, который умеет суммировать деньги. Этим классом является OrderMoney, это его бизнес ценность.

Поскольку OrderItemMoney - это тоже Money, мы вполне можем использовать в OrderMoney любые объекты класса Money. Это упрощает тестирование.

```c++
class OrderMoney final : public Money {
public:
	OrderMoney(const std::shared_ptr<const Money> &a, const std::shared_ptr<const Money> &b);
	...
};

int OrderMoney::amount() const
{
	if (a->currency() != b->currency()) {
		throw runtime_error("Multicurrency operations without convert");
	}
	return a->amount() + b->amount();
}
```

Этот класс не конвертирует валюту. Но конвертирование валюты может быть встроено в этот класс.
Кроме этого пока он может состоять только из двух позиций. Как быть с другим количеством позиций?

- [ ] $5 + 10CHF = $10 если курс обмена 2:1
- [x] $5 * 2 = $10
- [ ] Money это data class
- [ ] Преобразование Money в текст для отчета
- [x] Общая сумма по всем позициям (простой случай)
- [x] Переименовать TimesMoney в OrderItemMoney со всеми вытекающими.
- [ ] Заказ из одной позиции
- [ ] Заказ из трех и более позиций
- [ ] Обмен валют

Мне не нужно думать, как просуммировать сумму товаров по каждой позиции.
Это был бы императивный подход.
Каждая позиция, при получении суммы просто сконструирует нужную сумму и вернет ее для включения в OrderMoney.

[Продолжить](TUTORIAL5.ru.md)
