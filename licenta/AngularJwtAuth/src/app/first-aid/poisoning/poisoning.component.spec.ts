import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { PoisoningComponent } from './poisoning.component';

describe('PoisoningComponent', () => {
  let component: PoisoningComponent;
  let fixture: ComponentFixture<PoisoningComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ PoisoningComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(PoisoningComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
