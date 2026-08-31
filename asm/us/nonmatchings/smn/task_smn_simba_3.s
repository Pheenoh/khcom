.syntax unified
	.align 2, 0
	.global task_smn_simba_3
	.thumb
	.thumb_func
	.type task_smn_simba_3, %function
task_smn_simba_3: @ 080436C8
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _080436DC @ =0x00000155
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080436E4
	ldr r0, _080436E0 @ =0x02039B84
	b _080436E6
	.byte 0x00, 0x00
_080436DC: .4byte 0x00000155
_080436E0: .4byte 0x02039B84
_080436E4:
	ldr r0, _08043708 @ =0x02039B9C
_080436E6:
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	ldr r2, _0804370C @ =0xFFDFFFFF
	ands r0, r2
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	adds r0, r4, #0x0
	adds r0, #0x20
	bl TaskPoolDestroy
	pop {r4}
	pop {r0}
	bx r0
_08043708: .4byte 0x02039B9C
_0804370C: .4byte 0xFFDFFFFF
.syntax divided
