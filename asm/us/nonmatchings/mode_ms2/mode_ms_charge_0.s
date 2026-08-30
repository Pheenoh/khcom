.syntax unified
	.align 2, 0
	.global mode_ms_charge_0
	.thumb
	.thumb_func
	.type mode_ms_charge_0, %function
mode_ms_charge_0: @ 081068E0
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08106994 @ =0x02035C10
	ldr r0, _08106998 @ =0x00003A18
	bl func_08000918
	str r0, [r4, #0x00]
	bl func_08001F98
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006120
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1C
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x1D
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x02
	movs r1, #0x00
	movs r2, #0x1E
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x03
	movs r1, #0x00
	movs r2, #0x1F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x03
	bl func_080055C8
	movs r0, #0x01
	movs r1, #0x02
	bl func_080055C8
	movs r0, #0x02
	movs r1, #0x01
	bl func_080055C8
	movs r0, #0x03
	movs r1, #0x00
	bl func_080055C8
	ldr r0, _0810699C @ =0x02035C14
	movs r4, #0x00
	strh r4, [r0, #0x00]
	ldr r5, _081069A0 @ =0x02035C18
	movs r0, #0x04
	strh r0, [r5, #0x00]
	bl func_0810563C
	ldr r0, _081069A4 @ =0x02035CE0
	strh r4, [r0, #0x00]
	ldr r0, _081069A8 @ =0x02035CE2
	strh r4, [r0, #0x00]
	ldr r0, _081069AC @ =0x02035CE4
	strh r4, [r0, #0x00]
	ldr r0, _081069B0 @ =0x02035C3A
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	ble _081069C0
	ldr r1, _081069B4 @ =0x02035E18
	movs r2, #0x00
	movs r0, #0xB5
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	ldr r1, _081069B8 @ =0x02035E1C
	movs r0, #0xA0
	lsls r0, r0, #0x06
	str r0, [r1, #0x00]
	ldr r0, _081069BC @ =0x02035C16
	strh r2, [r0, #0x00]
	b _081069E2
	.byte 0x00, 0x00
_08106994: .4byte 0x02035C10
_08106998: .4byte 0x00003A18
_0810699C: .4byte 0x02035C14
_081069A0: .4byte 0x02035C18
_081069A4: .4byte 0x02035CE0
_081069A8: .4byte 0x02035CE2
_081069AC: .4byte 0x02035CE4
_081069B0: .4byte 0x02035C3A
_081069B4: .4byte 0x02035E18
_081069B8: .4byte 0x02035E1C
_081069BC: .4byte 0x02035C16
_081069C0:
	ldr r2, _08106AA8 @ =0x02035E18
	movs r3, #0x00
	ldsh r1, [r5, r3]
	lsls r0, r1, #0x03
	subs r0, r0, r1
	lsls r0, r0, #0x09
	movs r1, #0xAC
	lsls r1, r1, #0x08
	adds r0, r0, r1
	str r0, [r2, #0x00]
	ldr r1, _08106AAC @ =0x02035E1C
	movs r0, #0x80
	lsls r0, r0, #0x05
	str r0, [r1, #0x00]
	ldr r1, _08106AB0 @ =0x02035C16
	movs r0, #0x01
	strh r0, [r1, #0x00]
_081069E2:
	movs r1, #0x00
	ldr r2, _08106AB4 @ =0x02035D18
	mov r10, r2
	ldr r3, _08106AB8 @ =0x02035D48
	mov r9, r3
	ldr r0, _08106ABC @ =0x02035CE8
	mov r12, r0
	movs r5, #0x00
	ldr r2, _08106AC0 @ =0x02035D78
	mov r8, r2
_081069F6:
	movs r3, #0x00
	lsls r7, r1, #0x10
	asrs r1, r7, #0x10
	lsls r0, r1, #0x01
	adds r4, r0, r1
	lsls r6, r4, #0x02
_08106A02:
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #0x02
	adds r0, r0, r6
	mov r3, r12
	adds r1, r0, r3
	str r5, [r1, #0x00]
	mov r3, r10
	adds r1, r0, r3
	str r5, [r1, #0x00]
	add r0, r9
	str r5, [r0, #0x00]
	adds r0, r2, r4
	add r0, r8
	strb r5, [r0, #0x00]
	adds r2, #0x01
	lsls r2, r2, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0x02
	ble _08106A02
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r7, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	ble _081069F6
	movs r0, #0x00
	ldr r2, _08106AC4 @ =0x02035D84
	str r0, [r2, #0x00]
	ldr r3, _08106AC8 @ =0x02035D88
	str r0, [r3, #0x00]
	ldr r1, _08106ACC @ =0x02035D8C
	str r0, [r1, #0x00]
	ldr r2, _08106AD0 @ =0x02035D94
	str r0, [r2, #0x00]
	ldr r3, _08106AD4 @ =0x02035D98
	str r0, [r3, #0x00]
	ldr r1, _08106AD8 @ =0x02035DD8
	strb r0, [r1, #0x00]
	movs r1, #0x00
	ldr r2, _08106ADC @ =0x02035E0C
	strh r0, [r2, #0x00]
	ldr r3, _08106AE0 @ =0x02035E0E
	strh r0, [r3, #0x00]
	ldr r2, _08106AE4 @ =0x02035CB8
	strb r1, [r2, #0x00]
	movs r3, #0x01
	negs r3, r3
	adds r1, r3, #0x0
	ldr r2, _08106AE8 @ =0x02035CBA
	strh r1, [r2, #0x00]
	ldr r3, _08106AEC @ =0x02035CBC
	strh r0, [r3, #0x00]
	movs r2, #0xD0
	lsls r2, r2, #0x01
	ldr r1, _08106AF0 @ =0x09A3DBDC
	bl func_080050DC
	ldr r1, _08106AF4 @ =0x09A1913C
	ldr r2, _08106AF8 @ =0x00004A60
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _08106AFC @ =0x09A3B25C
	movs r4, #0xA0
	lsls r4, r4, #0x03
	movs r0, #0x00
	adds r2, r4, #0x0
	bl func_0800510C
	bl func_08104B2C
	ldrh r0, [r0, #0x04]
	cmp r0, #0x03
	bne _08106B04
	ldr r1, _08106B00 @ =0x09A3BD5C
	movs r0, #0x01
	adds r2, r4, #0x0
	bl func_0800510C
	b _08106B0E
_08106AA8: .4byte 0x02035E18
_08106AAC: .4byte 0x02035E1C
_08106AB0: .4byte 0x02035C16
_08106AB4: .4byte 0x02035D18
_08106AB8: .4byte 0x02035D48
_08106ABC: .4byte 0x02035CE8
_08106AC0: .4byte 0x02035D78
_08106AC4: .4byte 0x02035D84
_08106AC8: .4byte 0x02035D88
_08106ACC: .4byte 0x02035D8C
_08106AD0: .4byte 0x02035D94
_08106AD4: .4byte 0x02035D98
_08106AD8: .4byte 0x02035DD8
_08106ADC: .4byte 0x02035E0C
_08106AE0: .4byte 0x02035E0E
_08106AE4: .4byte 0x02035CB8
_08106AE8: .4byte 0x02035CBA
_08106AEC: .4byte 0x02035CBC
_08106AF0: .4byte 0x09A3DBDC
_08106AF4: .4byte 0x09A1913C
_08106AF8: .4byte 0x00004A60
_08106AFC: .4byte 0x09A3B25C
_08106B00: .4byte 0x09A3BD5C
_08106B04:
	ldr r1, _08106D4C @ =0x09A3B85C
	movs r0, #0x01
	adds r2, r4, #0x0
	bl func_0800510C
_08106B0E:
	ldr r0, _08106D50 @ =0x02035C18
	movs r1, #0x00
	ldsh r0, [r0, r1]
	bl func_081052C8
	ldr r1, _08106D54 @ =0x09A3C25C
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x02
	bl func_0800510C
	bl func_08104F2C
	bl func_08104FA4
	bl func_08104FF8
	bl func_08105090
	ldr r0, _08106D58 @ =0x09611AB8
	movs r1, #0x20
	bl func_08002A14
	ldr r1, _08106D5C @ =0x02035D90
	str r0, [r1, #0x00]
	ldr r0, _08106D60 @ =0x0908B1B4
	movs r1, #0x9A
	lsls r1, r1, #0x04
	bl func_080026A4
	ldr r1, _08106D64 @ =0x02035D9C
	str r0, [r1, #0x00]
	ldr r4, _08106D68 @ =0x02035DA0
	ldr r1, _08106D6C @ =0x09EEA164
	ldr r2, _08106D70 @ =0x09EEA148
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	ldr r0, _08106D74 @ =0x0908C3CE
	movs r1, #0x98
	lsls r1, r1, #0x02
	bl func_080026A4
	ldr r1, _08106D78 @ =0x02035DB8
	str r0, [r1, #0x00]
	ldr r4, _08106D7C @ =0x02035DC0
	ldr r1, _08106D80 @ =0x09EEA198
	ldr r2, _08106D84 @ =0x09EEA180
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	ldr r0, _08106D88 @ =0x099A7C78
	movs r1, #0x20
	bl func_080026A4
	ldr r1, _08106D8C @ =0x02035C40
	str r0, [r1, #0x00]
	ldr r0, _08106D90 @ =0x09A3DE7C
	movs r1, #0x20
	bl func_08002A14
	ldr r1, _08106D94 @ =0x02035C44
	str r0, [r1, #0x00]
	ldr r0, _08106D98 @ =0x099A6C82
	movs r1, #0xFE
	lsls r1, r1, #0x04
	bl func_080026A4
	ldr r1, _08106D9C @ =0x02035C48
	str r0, [r1, #0x00]
	ldr r4, _08106DA0 @ =0x02035C50
	ldr r5, _08106DA4 @ =0x09EF9AA4
	ldr r6, _08106DA8 @ =0x09EF9A68
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x01
	movs r2, #0x01
	bl func_080059A4
	ldr r4, _08106DAC @ =0x02035C68
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x01
	bl func_080059A4
	ldr r2, _08106DB0 @ =0x09617D58
	mov r8, r2
	mov r0, r8
	movs r1, #0x20
	bl func_08002A14
	ldr r1, _08106DB4 @ =0x02035C80
	str r0, [r1, #0x00]
	ldr r0, _08106DB8 @ =0x099A2194
	movs r1, #0x94
	lsls r1, r1, #0x04
	bl func_080026A4
	ldr r1, _08106DBC @ =0x02035C84
	str r0, [r1, #0x00]
	ldr r4, _08106DC0 @ =0x02035C88
	ldr r5, _08106DC4 @ =0x09EF9978
	ldr r6, _08106DC8 @ =0x09EF9928
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x03
	movs r2, #0x01
	bl func_080059A4
	ldr r4, _08106DCC @ =0x02035CA0
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	mov r0, r8
	movs r1, #0x20
	bl func_08002A14
	ldr r1, _08106DD0 @ =0x02035CC0
	str r0, [r1, #0x00]
	ldr r0, _08106DD4 @ =0x092028EC
	movs r1, #0xC0
	lsls r1, r1, #0x04
	bl func_080026A4
	ldr r1, _08106DD8 @ =0x02035CC4
	str r0, [r1, #0x00]
	ldr r0, _08106DDC @ =0x02035CC8
	ldr r1, _08106DE0 @ =0x09EEEAC8
	ldr r2, _08106DE4 @ =0x09EEEA98
	bl func_08005968
	ldr r4, _08106DE8 @ =0x02035DDC
	movs r0, #0x90
	lsls r0, r0, #0x01
	bl func_08000918
	str r0, [r4, #0x00]
	movs r1, #0x24
	bl func_08065ACC
	ldr r4, _08106DEC @ =0x02035DE4
	movs r0, #0xB4
	lsls r0, r0, #0x02
	bl func_08000918
	str r0, [r4, #0x00]
	movs r1, #0x5A
	bl func_08065ACC
	ldr r6, _08106DF0 @ =0x08159F38
	adds r0, r6, #0x0
	bl func_08065B54
	ldr r4, _08106DF4 @ =0x02035DF2
	strh r0, [r4, #0x00]
	ldr r5, _08106DF8 @ =0x02035DEC
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x03
	bl func_08000918
	str r0, [r5, #0x00]
	ldrh r1, [r4, #0x00]
	bl func_08065ACC
	ldr r4, _08106DFC @ =0x02035DF0
	ldr r1, [r5, #0x00]
	adds r0, r6, #0x0
	bl func_08065B6C
	strb r0, [r4, #0x00]
	ldr r6, _08106E00 @ =0x0815C204
	adds r0, r6, #0x0
	bl func_08065B54
	ldr r4, _08106E04 @ =0x02035DFA
	strh r0, [r4, #0x00]
	ldr r5, _08106E08 @ =0x02035DF4
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x03
	bl func_08000918
	str r0, [r5, #0x00]
	ldrh r1, [r4, #0x00]
	bl func_08065ACC
	ldr r4, _08106E0C @ =0x02035DF8
	ldr r1, [r5, #0x00]
	adds r0, r6, #0x0
	bl func_08065B6C
	strb r0, [r4, #0x00]
	ldr r6, _08106E10 @ =0x08159E10
	adds r0, r6, #0x0
	bl func_08065B54
	ldr r4, _08106E14 @ =0x02035E02
	strh r0, [r4, #0x00]
	ldr r5, _08106E18 @ =0x02035DFC
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x03
	bl func_08000918
	str r0, [r5, #0x00]
	ldrh r1, [r4, #0x00]
	bl func_08065ACC
	ldr r4, _08106E1C @ =0x02035E00
	ldr r1, [r5, #0x00]
	adds r0, r6, #0x0
	bl func_08065B6C
	strb r0, [r4, #0x00]
	ldr r6, _08106E20 @ =0x08159E18
	adds r0, r6, #0x0
	bl func_08065B54
	ldr r4, _08106E24 @ =0x02035E0A
	strh r0, [r4, #0x00]
	ldr r5, _08106E28 @ =0x02035E04
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x03
	bl func_08000918
	str r0, [r5, #0x00]
	ldrh r1, [r4, #0x00]
	bl func_08065ACC
	ldr r4, _08106E2C @ =0x02035E08
	ldr r1, [r5, #0x00]
	adds r0, r6, #0x0
	bl func_08065B6C
	strb r0, [r4, #0x00]
	bl func_08104BBC
	bl func_08104D18
	movs r0, #0x00
	bl func_08004FC8
	movs r0, #0x01
	bl func_08004FC8
	movs r0, #0x02
	bl func_0800501C
	movs r0, #0x03
	bl func_0800501C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08106D4C: .4byte 0x09A3B85C
_08106D50: .4byte 0x02035C18
_08106D54: .4byte 0x09A3C25C
_08106D58: .4byte 0x09611AB8
_08106D5C: .4byte 0x02035D90
_08106D60: .4byte 0x0908B1B4
_08106D64: .4byte 0x02035D9C
_08106D68: .4byte 0x02035DA0
_08106D6C: .4byte 0x09EEA164
_08106D70: .4byte 0x09EEA148
_08106D74: .4byte 0x0908C3CE
_08106D78: .4byte 0x02035DB8
_08106D7C: .4byte 0x02035DC0
_08106D80: .4byte 0x09EEA198
_08106D84: .4byte 0x09EEA180
_08106D88: .4byte 0x099A7C78
_08106D8C: .4byte 0x02035C40
_08106D90: .4byte 0x09A3DE7C
_08106D94: .4byte 0x02035C44
_08106D98: .4byte 0x099A6C82
_08106D9C: .4byte 0x02035C48
_08106DA0: .4byte 0x02035C50
_08106DA4: .4byte 0x09EF9AA4
_08106DA8: .4byte 0x09EF9A68
_08106DAC: .4byte 0x02035C68
_08106DB0: .4byte 0x09617D58
_08106DB4: .4byte 0x02035C80
_08106DB8: .4byte 0x099A2194
_08106DBC: .4byte 0x02035C84
_08106DC0: .4byte 0x02035C88
_08106DC4: .4byte 0x09EF9978
_08106DC8: .4byte 0x09EF9928
_08106DCC: .4byte 0x02035CA0
_08106DD0: .4byte 0x02035CC0
_08106DD4: .4byte 0x092028EC
_08106DD8: .4byte 0x02035CC4
_08106DDC: .4byte 0x02035CC8
_08106DE0: .4byte 0x09EEEAC8
_08106DE4: .4byte 0x09EEEA98
_08106DE8: .4byte 0x02035DDC
_08106DEC: .4byte 0x02035DE4
_08106DF0: .4byte 0x08159F38
_08106DF4: .4byte 0x02035DF2
_08106DF8: .4byte 0x02035DEC
_08106DFC: .4byte 0x02035DF0
_08106E00: .4byte 0x0815C204
_08106E04: .4byte 0x02035DFA
_08106E08: .4byte 0x02035DF4
_08106E0C: .4byte 0x02035DF8
_08106E10: .4byte 0x08159E10
_08106E14: .4byte 0x02035E02
_08106E18: .4byte 0x02035DFC
_08106E1C: .4byte 0x02035E00
_08106E20: .4byte 0x08159E18
_08106E24: .4byte 0x02035E0A
_08106E28: .4byte 0x02035E04
_08106E2C: .4byte 0x02035E08
.syntax divided
