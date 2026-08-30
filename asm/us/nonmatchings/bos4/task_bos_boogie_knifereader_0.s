.syntax unified
	.align 2, 0
	.global task_bos_boogie_knifereader_0
	.thumb
	.thumb_func
	.type task_bos_boogie_knifereader_0, %function
task_bos_boogie_knifereader_0: @ 080DB510
	push {r4, lr}
	add sp, #-0x004
	adds r4, r0, #0x0
	movs r0, #0x02
	str r0, [r4, #0x00]
	movs r1, #0x00
	movs r0, #0x00
	strh r0, [r4, #0x04]
	ldr r0, _080DB570 @ =0x0203C574
	strb r1, [r0, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x08
	movs r1, #0x05
	bl func_08000E64
	movs r2, #0x00
	movs r1, #0x04
	movs r3, #0x9E
	lsls r3, r3, #0x01
	adds r0, r4, r3
_080DB538:
	str r2, [r0, #0x00]
	subs r0, #0x04
	subs r1, #0x01
	cmp r1, #0x00
	bge _080DB538
	movs r0, #0x00
	adds r4, #0x1C
	ldr r1, _080DB574 @ =0x096FE0E8
	movs r2, #0xF8
	lsls r2, r2, #0x08
	movs r3, #0x90
	lsls r3, r3, #0x0A
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	bl func_0801B37C
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_0801C2DC
	adds r0, r4, #0x0
	bl func_0801BCD4
	add sp, #0x004
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DB570: .4byte 0x0203C574
_080DB574: .4byte 0x096FE0E8
.syntax divided
