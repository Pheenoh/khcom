.syntax unified
	.align 2, 0
	.global task_bos_ursula_thunder_1
	.thumb
	.thumb_func
	.type task_bos_ursula_thunder_1, %function
task_bos_ursula_thunder_1: @ 080DDDA4
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080128EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080DDDCC
	ldrh r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080DDDBC
	movs r0, #0x00
	b _080DDDCE
_080DDDBC:
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x08]
	movs r2, #0x00
	movs r3, #0xF4
	bl func_080155BC
	movs r0, #0x01
	strh r0, [r4, #0x00]
_080DDDCC:
	movs r0, #0x01
_080DDDCE:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
