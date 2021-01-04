import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { HeartAttackComponent } from './heart-attack.component';

describe('HeartAttackComponent', () => {
  let component: HeartAttackComponent;
  let fixture: ComponentFixture<HeartAttackComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ HeartAttackComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(HeartAttackComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
