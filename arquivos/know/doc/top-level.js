/**
 * PARTE 1: Definições de Classes
 * Baseado na hierarquia: Thing -> Resource -> Class/Property e Thing -> Literal
 */

class Thing {
  constructor(type, label, comment, sameAs) {
    this.type = type;
    this.label = label;
    this.comment = comment;
    this.sameAs = sameAs;
  }
}

class Literal extends Thing {
  constructor(type, label, comment, sameAs, format) {
    super(type, label, comment, sameAs);
    this.format = format;
  }
}

class Resource extends Thing {
  constructor(type, label, comment, sameAs) {
    super(type, label, comment, sameAs);
  }
}

class Class extends Resource {
  constructor(type, label, comment, sameAs, hasProperty) {
    super(type, label, comment, sameAs);
    this.hasProperty = hasProperty;
  }
}

class Property extends Resource {
  constructor(type, label, comment, sameAs, hasClass) {
    super(type, label, comment, sameAs);
    this.hasClass = hasClass;
  }
}

/**
 * PARTE 2: Instanciação dos Objetos (Base de Conhecimento)
 */

// --- Conceitos Fundamentais (Classes e Tipos) ---

const thing = new Class(
  "tm:class", 
  "coisa", 
  "tm:thing é a classe de todas as coisas.", 
  "owl:Thing", 
  "tm:sameAs"
);

const literal = new Thing(
  "tm:thing", 
  "literal", 
  "tm:literal é a classe dos valores literais, como números e strings.", 
  "rdfs:Literal"
);

const resource = new Thing(
  "tm:thing", 
  "resource", 
  "tm:resource é a classe de todas as entidades, de tudo que pode ser representado por um endereço.", 
  "rdfs:Resource"
);

const class_obj = new Resource(
  "tm:resource", 
  "classe", 
  "tm:class é a classe de todas as classes.", 
  "rdfs:Class"
);

const property = new Resource(
  "tm:resource", 
  "propriedade", 
  "tm:property é a classe de todas as propriedades das classes.", 
  "rdf:Property"
);

// --- Definição das Propriedades (Instâncias de Property) ---

const sameAs = new Property(
  "tm:property",
  "mesma coisa que",
  "tm:sameAs determina que duas coisas são iguais.",
  "owl:sameAs",
  "tm:thing"
);

const format = new Property(
  "tm:property",
  "formato",
  "tm:format determina o formato de um literal. Veja https://www.w3.org/2001/XMLSchema.",
  "owl:sameAs", // No RDF original consta como owl:sameAs
  "tm:literal"
);

const type = new Property(
  "tm:property",
  "tipo",
  "tm:type determina que um resource é uma instância de uma classe.",
  "rdf:type",
  "tm:resource"
);

const label = new Property(
  "tm:property",
  "rótulo",
  "nome do resource para humanos.",
  "rdfs:label",
  "tm:resource"
);

const comment = new Property(
  "tm:property",
  "comentário",
  "comentário sobre o que o resource representa.",
  "rdfs:comment",
  "tm:resource"
);

const hasProperty = new Property(
  "tm:property",
  "tem a propriedade",
  "tm:hasProperty determina uma propriedade que a classe possui.",
  "tm:hasProperty",
  "tm:class"
);

const hasClass = new Property(
  "tm:property",
  "da classe",
  "tm:hasClass determina que a propriedade é da classe.",
  "tm:hasClass",
  "tm:property"
);

// Exemplo de uso:
//console.log(thing.label); // "coisa"
//console.log(format.comment); // "tm:format determina o formato de um literal..."
//console.log(sameAs instanceof Resource); // true
// class_obj instanceof Object.getPrototypeOf(thing).constructor     // false
// thing     instanceof Object.getPrototypeOf(class_obj).constructor // true
// literal.constructor.name // 'Thing'

const dicionario = {
  "coisa": thing,
  "literal": literal,
  "resource": resource,
  "classe": class_obj,
  "propriedade": property,
  "tipo": type,
  "rótulo": label
  // ... adicione as outras palavras
};

function validarSentenca(sentenca) {
  const palavras = sentenca.toLowerCase().split(" ");
  
  // Exemplo simples: Sujeito (0) -> Predicado/Propriedade (1) -> Objeto (2)
  const sujeito = dicionario[palavras[0]];
  const predicado = dicionario[palavras[1]];
  const objeto = dicionario[palavras[2]];

  if (!sujeito || !predicado || !objeto) {
    return "Erro: Uma das palavras não existe na base de dados.";
  }

  // Validação semântica baseada na sua classe 'Property'
  // Verificamos se o predicado exige que o sujeito seja de uma classe específica
  const classeExigidaPeloPredicado = predicado.hasClass; // ex: "tm:resource"
  
  if (sujeito.type === classeExigidaPeloPredicado) {
    return `Válido: O ${sujeito.label} pode ter a propriedade ${predicado.label}.`;
  } else {
    return `Inválido: A propriedade ${predicado.label} pertence a ${classeExigidaPeloPredicado}, mas foi usada em um ${sujeito.type}.`;
  }
}

// Testando:
console.log(validarSentenca("resource tipo classe")); 
// Saída: Válido: O resource pode ter a propriedade tipo.
