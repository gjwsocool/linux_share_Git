from recall.context import Context
from typing import List
import recall.strategy as strategy
import concurrent.futures


strategies: List[strategy.RecallStrategy] = [
    strategy.MostRatingStrategy(),
    strategy.HighRatingStrategy()
]


def anime_recall(context: Context, n=20)-> List[int]:
    """
    returns a list of anime ids
    """
    with concurrent.futures.ThreadPoolExecutor() as executor:
        outputs=executor.map(lambda s:s.recall(context,n),strategies)
        outputs=[aid for l in outputs for aid in l]
        outputs=list(dict.fromkeys(outputs))
        return outputs


def similar_animes(context: Context, n=20) -> List[int]:
    stra=strategy.SimilarAnimeStrategy()
    return stra.recall(context,n)

