.syntax unified
	.align 2, 0
	.global task_bos_lst_snp_1
	.thumb
	.thumb_func
	.type task_bos_lst_snp_1, %function
task_bos_lst_snp_1: @ 081124C4
	push {r4, r5, r6, lr}
	add sp, #-0x008
	adds r5, r0, #0x0
	movs r6, #0x01
	ldrb r0, [r5, #0x00]
	adds r0, #0x08
	strb r0, [r5, #0x00]
	ldr r2, [r5, #0x04]
	ldr r0, [r5, #0x10]
	adds r2, r2, r0
	str r2, [r5, #0x04]
	ldr r1, [r5, #0x0C]
	ldr r0, [r5, #0x14]
	adds r1, r1, r0
	str r1, [r5, #0x0C]
	adds r0, #0x40
	str r0, [r5, #0x14]
	mov r4, sp
	adds r4, #0x06
	ldr r3, [r5, #0x08]
	str r1, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	bl func_0801909C
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0xC0
	ble _08112500
	movs r6, #0x00
_08112500:
	adds r0, r5, #0x0
	adds r0, #0x20
	bl func_08005A64
	adds r0, r6, #0x0
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
