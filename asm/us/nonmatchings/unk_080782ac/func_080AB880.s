.syntax unified
	.align 2, 0
	.global func_080AB880
	.thumb
	.thumb_func
	.type func_080AB880, %function
func_080AB880: @ 080AB880
	push {lr}
	movs r0, #0x07
	bl func_08084458
	movs r0, #0x06
	bl func_08084458
	movs r0, #0x05
	bl func_08084458
	movs r0, #0x05
	bl func_08084458
	movs r0, #0x04
	bl func_08084458
	movs r0, #0x03
	bl func_08084458
	movs r0, #0x04
	bl func_08084458
	movs r0, #0x03
	bl func_08084458
	movs r0, #0x02
	bl func_08084458
	movs r0, #0x02
	bl func_08084458
	movs r0, #0x01
	bl func_08084458
	movs r0, #0x00
	bl func_08084458
	movs r0, #0xB9
	bl func_08084458
	movs r0, #0xC1
	lsls r0, r0, #0x01
	bl func_08084458
	movs r0, #0xCF
	bl func_08084458
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
