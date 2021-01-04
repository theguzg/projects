import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { FemaleBodyComponent } from './female-body.component';

describe('FemaleBodyComponent', () => {
  let component: FemaleBodyComponent;
  let fixture: ComponentFixture<FemaleBodyComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ FemaleBodyComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(FemaleBodyComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
