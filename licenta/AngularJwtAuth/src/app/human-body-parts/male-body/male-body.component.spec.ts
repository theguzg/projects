import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { MaleBodyComponent } from './male-body.component';

describe('MaleBodyComponent', () => {
  let component: MaleBodyComponent;
  let fixture: ComponentFixture<MaleBodyComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ MaleBodyComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(MaleBodyComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
