.syntax unified
	.align 2, 0
	.global task_smn_dumbo_3
	.thumb
	.thumb_func
	.type task_smn_dumbo_3, %function
task_smn_dumbo_3: @ 08044250
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _08044264 @ =0x00000155
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0804426C
	ldr r0, _08044268 @ =0x02039B84
	b _0804426E
	.byte 0x00, 0x00
_08044264: .4byte 0x00000155
_08044268: .4byte 0x02039B84
_0804426C:
	ldr r0, _08044298 @ =0x02039B9C
_0804426E:
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	ldr r2, _0804429C @ =0xFFDFFFFF
	ands r0, r2
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
	ldr r0, _080442A0 @ =0x0000024E
	bl m4aSongNumStop
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	adds r0, r4, #0x0
	adds r0, #0x20
	bl TaskPoolDestroy
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08044298: .4byte 0x02039B9C
_0804429C: .4byte 0xFFDFFFFF
_080442A0: .4byte 0x0000024E
.syntax divided
