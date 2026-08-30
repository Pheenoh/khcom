.syntax unified
	.align 2, 0
	.global task_title_logo_1
	.thumb
	.thumb_func
	.type task_title_logo_1, %function
task_title_logo_1: @ 080D63F8
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080D6280
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D642A
	ldr r2, _080D6434 @ =0x02034ECC
	ldrb r1, [r2, #0x00]
	cmp r1, #0x00
	bne _080D642A
	ldr r0, [r4, #0x48]
	subs r0, #0x4C
	str r0, [r4, #0x48]
	ldr r0, [r4, #0x4C]
	adds r0, #0x06
	str r0, [r4, #0x4C]
	cmp r0, #0xFF
	ble _080D642A
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r4, #0x4C]
	str r1, [r4, #0x48]
	movs r0, #0x01
	strb r0, [r2, #0x00]
_080D642A:
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080D6434: .4byte 0x02034ECC
.syntax divided
