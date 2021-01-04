import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { HumanShapeComponent } from './human-shape.component';

describe('HumanShapeComponent', () => {
  let component: HumanShapeComponent;
  let fixture: ComponentFixture<HumanShapeComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ HumanShapeComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(HumanShapeComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
