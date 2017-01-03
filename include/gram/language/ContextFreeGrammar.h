#ifndef GRAM_LANGUAGE_CONTEXT_FREE_GRAMMAR
#define GRAM_LANGUAGE_CONTEXT_FREE_GRAMMAR

#include <memory>

#include <gram/language/symbol/Option.h>
#include <gram/language/Grammar.h>

namespace gram {
/**
 * Class.
 */
class ContextFreeGrammar : public Grammar {
 public:
  ContextFreeGrammar();
  virtual ~ContextFreeGrammar() = default;
  Phenotype expand(const Genotype& genotype);
  void addRule(std::string name, std::shared_ptr<NonTerminal> rule);
  std::shared_ptr<NonTerminal> ruleNamed(std::string name);
  virtual std::shared_ptr<NonTerminal> startRule() const;
 private:
  std::shared_ptr<NonTerminal> start;
  std::unordered_map<std::string, std::shared_ptr<NonTerminal>> rules;
  Phenotype& recursiveExpand(Phenotype& phenotype,
                            const NonTerminal& nonTerminal,
                            const Genotype& genotype,
                            unsigned long& geneCount) const;
};
}

#endif // GRAM_LANGUAGE_CONTEXT_FREE_GRAMMAR