.syntax unified
	.align 2, 0
	.global task_bos_ga_3
	.thumb
	.thumb_func
	.type task_bos_ga_3, %function
task_bos_ga_3: @ 080FB890
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	movs r5, #0x00
	adds r4, r6, #0x0
	adds r4, #0x20
_080FB89A:
	adds r0, r4, #0x0
	bl func_080F8374
	movs r0, #0xD4
	lsls r0, r0, #0x01
	adds r4, r4, r0
	adds r5, #0x01
	cmp r5, #0x05
	bls _080FB89A
	ldr r1, _080FB8D4 @ =0x00000A28
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	movs r1, #0xA3
	lsls r1, r1, #0x04
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r1, _080FB8D8 @ =0x00000A34
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080FB8D4: .4byte 0x00000A28
_080FB8D8: .4byte 0x00000A34
	.byte 0x41, 0x60, 0x82, 0x8A, 0x01, 0x21, 0x11, 0x43, 0x81, 0x82, 0x70, 0x47
.syntax divided
