.syntax unified
	.align 2, 0
	.global func_080DFEBC
	.thumb
	.thumb_func
	.type func_080DFEBC, %function
func_080DFEBC: @ 080DFEBC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	adds r7, r2, #0x0
	bl func_080DFB8C
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _080DFED2
	movs r0, #0x00
	b _080DFF16
_080DFED2:
	ldr r0, [r4, #0x08]
	cmp r0, r7
	bge _080DFEF6
	ldrb r1, [r4, #0x02]
	cmp r1, #0x04
	beq _080DFEE2
	cmp r1, #0x06
	bne _080DFF16
_080DFEE2:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl func_080E86C8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DFF10
_080DFEF2:
	ldr r0, [r4, #0x08]
	b _080DFF16
_080DFEF6:
	ldrb r0, [r4, #0x02]
	cmp r0, #0x03
	beq _080DFF00
	cmp r0, #0x05
	bne _080DFF14
_080DFF00:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl func_080E86C8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DFEF2
_080DFF10:
	ldr r0, [r4, #0x0C]
	b _080DFF16
_080DFF14:
	ldr r0, [r4, #0x0C]
_080DFF16:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
