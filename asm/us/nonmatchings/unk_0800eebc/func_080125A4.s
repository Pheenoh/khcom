.syntax unified
	.align 2, 0
	.global func_080125A4
	.thumb
	.thumb_func
	.type func_080125A4, %function
func_080125A4: @ 080125A4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r4, _08012604 @ =0x020348E8
	adds r0, r4, #0x0
	bl func_08012330
	ldr r5, _08012608 @ =0x020348F8
	adds r0, r5, #0x0
	bl func_08012330
	ldr r0, _0801260C @ =0x02034908
	mov r8, r0
	bl func_08012330
	ldr r6, _08012610 @ =0x02034918
	adds r0, r6, #0x0
	bl func_08012330
	adds r0, r4, #0x0
	adds r1, r4, #0x0
	bl func_0801235C
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_0801235C
	mov r0, r8
	adds r1, r4, #0x0
	bl func_0801235C
	adds r0, r5, #0x0
	adds r1, r5, #0x0
	bl func_0801235C
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl func_0801235C
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	bl func_0801235C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08012604: .4byte 0x020348E8
_08012608: .4byte 0x020348F8
_0801260C: .4byte 0x02034908
_08012610: .4byte 0x02034918
.syntax divided
