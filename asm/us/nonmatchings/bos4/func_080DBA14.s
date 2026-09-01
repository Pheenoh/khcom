.syntax unified
	.align 2, 0
	.global func_080DBA14
	.thumb
	.thumb_func
	.type func_080DBA14, %function
func_080DBA14: @ 080DBA14
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0xA1
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080DBA44
	ldr r0, [r4, #0x1C]
	ldr r0, [r0, #0x04]
	bl func_080DD1FC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080DBA44
	ldr r0, [r4, #0x20]
	ldr r0, [r0, #0x04]
	bl func_080DD1FC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080DBA44
	movs r0, #0x01
	b _080DBA46
_080DBA44:
	movs r0, #0x00
_080DBA46:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
