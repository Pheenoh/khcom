.syntax unified
	.align 2, 0
	.global func_080DDE74
	.thumb
	.thumb_func
	.type func_080DDE74, %function
func_080DDE74: @ 080DDE74
	push {r4, lr}
	ldr r4, [r0, #0x08]
	ldrh r1, [r0, #0x00]
	adds r1, #0x01
	ldrh r3, [r0, #0x02]
	ldr r2, [r4, #0x00]
	lsls r0, r3, #0x02
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	cmp r1, r0
	ble _080DDE96
	adds r0, r3, #0x1
	ldrh r4, [r4, #0x04]
	cmp r0, r4
	blt _080DDE96
	movs r0, #0x01
	b _080DDE98
_080DDE96:
	movs r0, #0x00
_080DDE98:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
