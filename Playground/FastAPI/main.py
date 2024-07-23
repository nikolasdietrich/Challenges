from enum import Enum
from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()


class Category(Enum):
    TOOLS = "tools"
    CONSUMABLES = "consumables"


class Item(BaseModel):
    name: str
    price: float
    count: int
    id: int
    category: Category


DEFAULT_ITEMS = {
    0: Item(name="Hammer", price=9.99, count=20, id=0, category=Category.TOOLS)
}


class Inventory:
    def __init__(self) -> None:
        self.items = DEFAULT_ITEMS
        self.balance = 0.0

    def get_all_information(self) -> dict[str, dict[int, Item] | float]:
        return {"balance": self.balance, "items": self.items}


Sample_Shop = Inventory()


@app.get("/")
def get_shop_info() -> dict[str, dict[int, Item] | float]:
    return Sample_Shop.get_all_information()


def main():
    print(Sample_Shop.balance)


if __name__ == "__main__":
    main()
